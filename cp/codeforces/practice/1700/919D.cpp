// https://codeforces.com/contest/919/problem/D
// Substring

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 3e5 + 5;

vector<int> g[N];
int deg[N];

int toposort(string &str, vector<vector<int>> &dp, int n)
{
    queue<int> q;
    vector<int> order;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0)
            q.push(i);
    int cnt = 0, res = -1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int e : g[cur])
        {
            for (int j = 0; j < 26; j++)
                dp[e][j] = max(dp[e][j], dp[cur][j] + ((str[e - 1] - 'a') == j));
            if (--deg[e] == 0)
                q.push(e);
        }
        cnt++;
    }
    if (cnt != n)
        return res;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            res = max(res, dp[i][j]);
    return res;
}

int solve()
{
    int n, m, u, v;
    string str;
    cin >> n >> m >> str;
    for (int i = 1; i <= n; i++)
        deg[i] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        deg[v]++;
    }
    vector<vector<int>> dp(n + 1, vector<int>(26));
    for (int i = 1; i <= n; i++)
        dp[i][str[i - 1] - 'a']++;
    return toposort(str, dp, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}