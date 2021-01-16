// https://codeforces.com/contest/731/problem/C
// Socks

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 1;
int c[N];
vector<int> g[N];
bool vis[N];

int dfs(int cur, unordered_map<int, int> &mp)
{
    vis[cur] = true;
    mp[c[cur]]++;
    int cnt = 1;
    for (int e : g[cur])
        if (!vis[e])
            cnt += dfs(e, mp);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, u, v, res = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        vis[i] = false;
    }
    while (m-- > 0)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        unordered_map<int, int> mp;
        int cnt = dfs(i, mp), mx = 0;
        for (auto v : mp)
            mx = max(mx, v.second);
        res += cnt - mx;
    }
    cout << res << "\n";
    return 0;
}