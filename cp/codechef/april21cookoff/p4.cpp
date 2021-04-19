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

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mstree ms(n);
    ms.build(arr);
    map<int, ll> mp;
    ll inv = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int cnt = ms.query(i, n - 1, arr[i]);
        mp[arr[i]] += 1ll * cnt;
        inv += 1ll * cnt;
    }
    cout << inv << "\n";
    vector<ll> sum(n), pre(n);
    for (int i = 0; i < n; i++)
        sum[i] = mp[arr[i]];
    pre[0] = sum[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + sum[i];
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        int low = i, high = n - 1, id = -1;
        ll prev = (i - 1 > 0) ? pre[i - 1] : 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (pre[mid] - prev >= inv)
            {
                id = min(id, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if (id >= 0)
        {
            res += n - i - (id - i);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}