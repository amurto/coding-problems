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

const int inf = 1e9 + 7;
int solve()
{
    int n, m, low = 1, high = inf, res = inf;
    ll k;
    cin >> n >> m >> k;
    vector<int> arr(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    if (k == 1)
    {
        for (int i = 1; i <= n; i++)
            res = min(res, arr[i]);
        return res;
    }
    auto calc = [&](int x) -> bool
    {
        int v = 0, mx = 0;
        vector<int> deg(n + 1), dp(n + 1);
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] <= x)
            {
                v++;
                for (int e : g[i])
                    if (arr[e] <= x)
                        deg[e]++;
            }
        }
        for (int i = 1; i <= n; i++)
            if (arr[i] <= x && deg[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            v--;
            mx = max(mx, dp[cur]);
            for (int e : g[cur])
            {
                if (arr[e] <= x && --deg[e] == 0)
                {
                    q.push(e);
                    dp[e] = max(dp[e], dp[cur] + 1);
                }
            }
        }
        if (v > 0 || mx >= k - 1)
            return true;
        return false;
    };
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (calc(mid))
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res >= inf ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}