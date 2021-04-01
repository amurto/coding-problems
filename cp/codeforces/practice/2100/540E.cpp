// https://codeforces.com/contest/540/problem/E
// Infinite Inversions

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
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
    int n, a, b;
    cin >> n;
    vector<int> arr;
    vector<pii> op(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        arr.pb(a);
        arr.pb(b);
        op[i].first = a;
        op[i].second = b;
    }
    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    int sz = arr.size();
    vector<int> pos(sz);
    map<int, int> mp;
    for (int i = 0; i < sz; i++)
    {
        mp[arr[i]] = i;
        pos[i] = arr[i];
    }
    for (int i = 0; i < n; i++)
        swap(arr[mp[op[i].first]], arr[mp[op[i].second]]);
    mstree ms(sz);
    ms.build(arr);
    ll res = 0;
    for (int i = 0; i < sz - 1; i++)
        res += ms.query(i + 1, sz - 1, arr[i]);
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] < pos[i])
        {
            int lb = arr[i] + 1, rb = pos[i] - 1;
            int c = ms.query(0, sz - 1, rb + 1) - ms.query(0, sz - 1, lb);
            res += rb - lb + 1 - c;
        }
        else if (arr[i] > pos[i])
        {
            int lb = pos[i] + 1, rb = arr[i] - 1;
            int c = ms.query(0, sz - 1, rb + 1) - ms.query(0, sz - 1, lb);
            res += rb - lb + 1 - c;
        }
    }
    cout << res << "\n";
    return 0;
}