// https://codeforces.com/contest/1288/problem/E
// Messenger Simulator

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Merge Sort Tree
struct mstree
{
    int len;
    vector<vector<int>> t;
    mstree(int l)
    {
        len = l;
        t.resize(4 * len);
    }

    vector<int> merge(int l, int r)
    {
        int sz1 = t[l].size(), sz2 = t[r].size();
        vector<int> arr(sz1 + sz2);
        int i = 0, j = 0, idx = 0;
        while (i < sz1 && j < sz2)
        {
            arr[idx++] = (t[l][i] < t[r][j]) ? t[l][i++] : t[r][j++];
        }
        while (i < sz1)
        {
            arr[idx++] = t[l][i++];
        }
        while (j < sz2)
        {
            arr[idx++] = t[r][j++];
        }
        return arr;
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v].pb(arr[tl]);
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v] = merge(v << 1, v << 1 | 1);
    }

    int query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, int e)
    {
        if (l > tr || r < tl)
            return 0;
        if (tl >= l && tr <= r)
            return lower_bound(t[v].begin(), t[v].end(), e) - t[v].begin();
        int32_t tm = (tl + tr) >> 1;
        return query(v << 1, tl, tm, l, r, e) + query(v << 1 | 1, tm + 1, tr, l, r, e);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    int query(const int32_t &l, const int32_t &r, int e)
    {
        return query(1, 0, len - 1, l, r, e);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> msg(m), nxt(m, m), fst(n + 1, m), mn(n + 1), mx(n + 1), last(n + 1, m);
    iota(mn.begin(), mn.end(), 0);
    iota(mx.begin(), mx.end(), 0);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> msg[i];
        g[msg[i]].pb(i);
        mn[msg[i]] = 1;
        fst[msg[i]] = min(fst[msg[i]], i);
    }
    for (int i = m - 1; i >= 0; i--)
    {
        nxt[i] = last[msg[i]];
        last[msg[i]] = i;
    }
    mstree ms(m), inv(n + 1);
    ms.build(nxt);
    inv.build(fst);
    for (int i = 1; i <= n; i++)
    {
        if (g[i].empty())
            continue;
        g[i].pb(m);
        for (int j = 1; j < g[i].size(); j++)
        {
            int len = g[i][j] - g[i][j - 1];
            int q = ms.query(g[i][j - 1], g[i][j] - 1, g[i][j]);
            mx[i] = max(mx[i], len - q);
        }
    }
    for (int i = n - 1; i >= 1; i--)
        mx[i] = max(mx[i], i + inv.query(i + 1, n, fst[i]));
    for (int i = 1; i <= n; i++)
        cout << mn[i] << " " << mx[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}