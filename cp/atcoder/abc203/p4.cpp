#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

struct node
{
    int v = 0; // identity
    node() {}
    node(int val)
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
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
        identity_element = node();
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

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const int &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            t[v].v += upd;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, upd);
        rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const int &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

int median(segtree<node> &s, int e, int sz)
{
    int low = 0, high = sz - 1, med = sz - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int sum = s.query(0, mid).v;
        if (sum >= e)
        {
            med = min(med, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return med;
}

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<int> seq;
    map<int, int> mask;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            seq.pb(grid[i][j]);
        }
    }
    sort(seq.begin(), seq.end());
    seq.resize(unique(seq.begin(), seq.end()) - seq.begin());
    int sz = seq.size();
    for (int i = 0; i < sz; i++)
        mask[seq[i]] = i;
    vector<int> cnt(sz);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cnt[mask[grid[i][j]]]++;
    segtree<node> s(sz);
    int res = 1e9 + 5, mid = (k * k) / 2 + 1;
    for (int i = 0; i <= n - k; i++)
    {
        for (int r = i; r < i + k; r++)
            for (int c = 0; c < k; c++)
                s.rupd(mask[grid[r][c]], mask[grid[r][c]], 1);
        res = min(res, seq[median(s, mid, sz)]);
        for (int c = 1; c <= n - k; c++)
        {
            int prev = c - 1;
            for (int r = i; r < i + k; r++)
                s.rupd(mask[grid[r][prev]], mask[grid[r][prev]], -1);
            for (int r = i; r < i + k; r++)
                s.rupd(mask[grid[r][c + k - 1]], mask[grid[r][c + k - 1]], 1);
            res = min(res, seq[median(s, mid, sz)]);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}