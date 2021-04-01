// https://codeforces.com/contest/301/problem/D
// Yaroslav and Divisors

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;

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

    void merge(int v, int l, int r)
    {
        int sz1 = t[l].size(), sz2 = t[r].size();
        t[v].resize(sz1 + sz2);
        int i = 0, j = 0, idx = 0;
        while (i < sz1 && j < sz2)
        {
            t[v][idx++] = (t[l][i] < t[r][j]) ? t[l][i++] : t[r][j++];
        }
        while (i < sz1)
        {
            t[v][idx++] = t[l][i++];
        }
        while (j < sz2)
        {
            t[v][idx++] = t[r][j++];
        }
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v] = arr[tl];
            sort(t[v].begin(), t[v].end());
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        merge(v, v << 1, v << 1 | 1);
    }

    // number of elements less than e in given range
    int query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
            return 0;
        if (tl >= l && tr <= r)
            return lower_bound(t[v].begin(), t[v].end(), r + 1) - t[v].begin();
        int32_t tm = (tl + tr) >> 1;
        return query(v << 1, tl, tm, l, r) + query(v << 1 | 1, tm + 1, tr, l, r);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    int query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    int n, m, l, r;
    // cin >> n >> m;
    n = 2e5, m = 0;
    vector<int> arr(n), vis(N), pos(N);
    for (int i = 0; i < n; i++)
    {
        // cin >> arr[i];
        arr[i] = i + 1;
        vis[arr[i]] = 1;
        pos[arr[i]] = i;
    }
    vector<vector<int>> seq(n);
    for (int i = 1; i < N; i++)
    {
        if (vis[i] == 0)
            continue;
        for (int j = 2 * i; j < N; j += i)
            if (vis[j])
                seq[min(pos[i], pos[j])].pb(max(pos[i], pos[j]));
    }
    mstree ms(n);
    ms.build(seq);
    // while (m-- > 0)
    // {
    //     cin >> l >> r;
    //     cout << ms.query(l - 1, r - 1) + r - l + 1 << "\n";
    // }
    cout << ms.query(0, n - 1) << "\n";
    return 0;
}