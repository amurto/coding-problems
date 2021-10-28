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

const int inf = 1e7;
void dfs(vector<vector<int>> &g, vector<int> &arr, int cur, int last, int p)
{
    int cnt = 0;
    for (int e : g[cur])
    {
        if (e != last)
        {
            dfs(g, arr, e, cur, p ^ 1);
            cnt++;
        }
    }
    if (p == 1)
    {
        if (cnt == 0)
            arr.pb(1);
        else if (cnt > 1)
            arr.pb(cnt - 1);
    }
}

// O(n*sqrt(n))
// If sum of array is n, then number of distinct values in array is bounded by sqrt(n)
vector<bool> possibleSqrt(vector<int> &arr, int n, int sum)
{
    sort(arr.begin(), arr.end());
    vector<bool> vis(sum + 1);
    vis[0] = true;
    for (int i = 0; i < n; i++)
    {
        int r = i;
        while (r < n && arr[r] == arr[i])
            r++;
        vector<int> cnt(sum + 1);
        for (int cur = arr[i]; cur <= sum; cur++)
        {
            if (!vis[cur] && vis[cur - arr[i]] && cnt[cur - arr[i]] < r - i)
            {
                cnt[cur] = cnt[cur - arr[i]] + 1;
                vis[cur] = true;
            }
        }
        i = r - 1;
    }
    return vis;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n + 1);
    vector<int> arr;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(g, arr, 1, 1, 1);
    int sz = (int)arr.size();
    int sum = 0;
    for (int x : arr)
        sum += x;

    if (q == 1)
        cout << sum << "\n";
    else
    {
        if (arr.empty())
            cout << "0\n";
        else
        {
            vector<bool> vis = possibleSqrt(arr, sz, n);
            int mn = inf;
            for (int i = 0; i <= n; i++)
                if (vis[i])
                    mn = min(mn, abs((sum - i) - i));
            cout << mn << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}