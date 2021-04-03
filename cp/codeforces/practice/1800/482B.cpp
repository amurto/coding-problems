// https://codeforces.com/contest/482/problem/B
// Interesting Array
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int b = 31;

struct node
{
    int v = INT_MAX; // identity
    node() {}
    node(int val)
    {
        v = val;
    }
    void merge(const node &l, const node &r)
    {
        v = l.v & r.v;
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
        if (tl >= l && tr <= r)
            return t[v];
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
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
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), l(m), r(m), q(m);
    vector<vector<int>> st(n + 1, vector<int>(b));
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i] >> q[i];
        l[i]--;
        r[i]--;
        for (int j = 0; j < b; j++)
        {
            if (q[i] & (1 << j))
            {
                st[l[i]][j]++;
                st[r[i] + 1][j]--;
            }
        }
    }
    for (int j = 0; j < b; j++)
        for (int i = 1; i < n; i++)
            st[i][j] += st[i - 1][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b; j++)
            if (st[i][j] > 0)
                arr[i] |= (1 << j);
    segtree<node> s(n);
    s.build(arr);
    for (int i = 0; i < m; i++)
    {
        if (s.query(l[i], r[i]).v != q[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}