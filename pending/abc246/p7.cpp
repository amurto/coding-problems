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

const int inf = 1e9;
int solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> arr(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    auto dfs = [&](const auto &self, int cur, int last, int req) -> int
    {
        int val = -inf;
        if (g[cur].size() == 1 && g[cur][0] == last)
            return 0;
        for (int e : g[cur])
            if (e != last)
                val = max(val, self(self, e, cur, req));
        for (int e : g[cur])
            if (e != last && arr[e] >= req)
                val++;
        return val - 1;
    };
    int low = 0, high = 1e9;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (dfs(dfs, 1, 1, mid) > 0)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
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