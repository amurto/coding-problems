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

// Struct DSU
struct dsu
{
    int n;
    vector<int> parent, cap;
    dsu(int l)
    {
        n = l;
        parent.resize(n + 1);
        cap.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            cap[i] = 1;
        }
    }

    int root(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = root(parent[x]);
    }

    bool merge_nodes(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return false;
        // by size (capacity)
        if (cap[rx] < cap[ry])
            swap(rx, ry);
        cap[rx] += cap[ry];
        parent[ry] = parent[rx];
        return true;
    }
};

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<int> arr(n), ids(n);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i1, int i2)
         { return arr[i1] > arr[i2]; });
    dsu ds(n);
    int c = 0;
    for (int i = 0; i < n;)
    {
        int r = i;
        while (r < n && arr[ids[i]] == arr[ids[r]])
        {
            vis[ids[r]] = true;
            r++;
        }
        c += (r - i);
        for (int j = i; j < r; j++)
        {
            int id = ids[j];
            int prev = (id - 1 + n) % n, nxt = (id + 1) % n;
            if (vis[prev] && ds.merge_nodes(prev, id))
                c--;
            if (vis[nxt] && ds.merge_nodes(id, nxt))
                c--;
        }
        int nxt_val = 0;
        if (r < n)
            nxt_val = arr[ids[r]];
        res += 1ll * c * (arr[ids[i]] - nxt_val);
        i = r;
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