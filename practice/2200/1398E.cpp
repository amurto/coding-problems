// https://codeforces.com/contest/1398/problem/E
// Two Types of Spells

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct node
{
    ll v = 0; // identity
    node() {}
    node(ll val)
    {
        v = val;
    }
    void merge(const node &l, const node &r)
    {
        v = l.v + r.v;
    }
};

template <typename node>
struct segtree
{
    int len;
    vector<node> t;
    node identity_element;
    segtree() = default;
    void init(int l)
    {
        len = l;
        t.resize(4 * len);
        identity_element = node();
    }
    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v].v = arr[tl];
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
            return identity_element;
        if (l <= tl && tr <= r)
            return t[v];
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // pupd = point update
    void pupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const ll &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            t[v].v += upd;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        pupd(v << 1, tl, tm, l, r, upd);
        pupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    // kth element from left
    // O(logn)
    int find_kth_left(const int32_t &v, const int32_t &tl, const int32_t &tr, const int k)
    {
        if (t[v].v == 0)
            return -1;
        if (tl == tr)
            return tl;
        int32_t tm = (tl + tr) >> 1;
        if (t[v << 1].v >= k)
            return find_kth_left(v << 1, tl, tm, k);
        return find_kth_left(v << 1 | 1, tm + 1, tr, k - t[v << 1].v);
    }

    // kth element from right
    // O(logn)
    int find_kth_right(const int32_t &v, const int32_t &tl, const int32_t &tr, const int k)
    {
        if (t[v].v == 0)
            return -1;
        if (tl == tr)
            return tl;
        int32_t tm = (tl + tr) >> 1;
        if (t[v << 1 | 1].v >= k)
            return find_kth_right(v << 1 | 1, tm + 1, tr, k);
        return find_kth_right(v << 1, tl, tm, k - t[v << 1 | 1].v);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void pupd(const int32_t &l, const int32_t &r, const ll &upd)
    {
        pupd(1, 0, len - 1, l, r, upd);
    }
    int find_kth_left(const int k)
    {
        return find_kth_left(1, 0, len - 1, k);
    }
    int find_kth_right(const int k)
    {
        return find_kth_right(1, 0, len - 1, k);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> tp(n), op(n, 1);
    vector<ll> dmg(n);
    vector<vector<ll>> nums(2);
    for (int i = 0; i < n; i++)
    {
        cin >> tp[i] >> dmg[i];
        if (dmg[i] < 0)
        {
            dmg[i] *= -1;
            op[i] = -1;
        }
        if (op[i] == 1)
            nums[tp[i]].pb(dmg[i]);
    }
    array<int, 2> sz{0, 0}, cnt{0, 0};
    array<ll, 2> sums{0, 0};
    vector<segtree<node>> ids(2), segsum(2);
    for (int i = 0; i < 2; i++)
    {
        nums[i].pb(0);
        sort(nums[i].begin(), nums[i].end());
        nums[i].resize(unique(nums[i].begin(), nums[i].end()) - nums[i].begin());
        sz[i] = (int)nums[i].size();
        ids[i].init(sz[i]);
        segsum[i].init(sz[i]);
    }
    for (int i = 0; i < n; i++)
    {
        ll res = 0;
        sums[tp[i]] += dmg[i] * op[i];
        cnt[tp[i]] += op[i];
        int pos = lower_bound(nums[tp[i]].begin(), nums[tp[i]].end(), dmg[i]) - nums[tp[i]].begin();
        ids[tp[i]].pupd(pos, pos, op[i]);
        segsum[tp[i]].pupd(pos, pos, dmg[i] * op[i]);
        if (cnt[1] == 0)
            res = sums[0];
        else
        {
            if (cnt[0] == 0)
            {
                int id = ids[1].find_kth_left(1);
                res = 2 * sums[1] - nums[1][id];
            }
            else
            {
                res = sums[0] + 2 * sums[1];
                int low = 1, high = min(cnt[0], cnt[1]), best = 1;
                while (low <= high)
                {
                    int mid = low + (high - low) / 2;
                    int e0 = ids[0].find_kth_right(mid), e1 = ids[1].find_kth_left(mid);
                    if (nums[0][e0] > nums[1][e1])
                    {
                        best = max(best, mid);
                        low = mid + 1;
                    }
                    else
                        high = mid - 1;
                }
                int id0 = ids[0].find_kth_right(best);
                int id1 = ids[1].find_kth_left(best);
                res += segsum[0].query(id0, segsum[0].len - 1).v;
                res -= segsum[1].query(0, id1).v;
            }
        }
        cout << res << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}