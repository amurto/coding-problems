#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

struct node
{
    int v1 = 0, v2 = 0; // identity
    node() {}
    node(int val1, int val2)
    {
        v1 = val1;
        v2 = val2;
    }
    void merge(const node &l, const node &r)
    {
        v1 = max(l.v1, r.v1);
        v2 = max(l.v2, r.v2);
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
    segtree() = default;

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v].v1 = arr[tl].first;
            t[v].v2 = arr[tl].second;
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
    void pupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const pii &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            t[v].v1 = upd.first;
            t[v].v2 = upd.second;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        pupd(v << 1, tl, tm, l, r, upd);
        pupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
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
    void pupd(const int32_t &l, const int32_t &r, const pii &upd)
    {
        pupd(1, 0, len - 1, l, r, upd);
    }
};

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<pii> chocs(n), boxes(m);
    vector<ll> C(m), D(m);
    for (int i = 0; i < n; i++)
        cin >> chocs[i].first;
    for (int i = 0; i < n; i++)
        cin >> chocs[i].second;
    for (int i = 0; i < m; i++)
        cin >> boxes[i].first;
    for (int i = 0; i < m; i++)
        cin >> boxes[i].second;
    sort(chocs.begin(), chocs.end());
    sort(boxes.begin(), boxes.end());
    segtree<node> s(m);
    s.build(boxes);
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = m - 1, id = m;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            node v = s.query(0, mid);
            if (v.v1 >= chocs[i].first && v.v2 >= chocs[i].second)
            {
                id = min(id, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if (id == m)
            return false;
        else
            s.pupd(id, id, {0, 0});
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}