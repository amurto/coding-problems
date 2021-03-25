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

    // number of elements less than e in given range
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<ll> res(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mstree ms(n);
    ms.build(arr);
    for (int i = 0; i < n; i++)
        res[0] += ms.query(i + 1, n - 1, arr[i]);
    for (int i = 1; i < n; i++)
        res[i] = res[i - 1] + n - 2 * arr[i - 1] - 1;
    for (ll r : res)
        cout << r << "\n";
    return 0;
}