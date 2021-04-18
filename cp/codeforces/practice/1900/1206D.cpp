// https://codeforces.com/contest/1206/problem/D
// Shortest Cycle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e9 + 7;

int bfs(vector<vector<int>> &g, int u, int v, int n)
{
    int d = 1;
    vector<bool> vis(n);
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (g[cur][i] && !vis[i])
                {
                    if (i == v)
                        return d + 1;
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        d++;
    }
    return inf;
}

int solve()
{
    int n, res = inf;
    ll x;
    cin >> n;
    vector<ll> arr, cnt(62);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > 0)
            arr.pb(x);
        for (int i = 0; x > 0; i++, x >>= 1)
            cnt[i] += (x & 1);
    }
    n = arr.size();
    if (n == 0)
        return -1;
    for (int i = 0; i < 62; i++)
        if (cnt[i] >= 3)
            return 3;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            g[i][j] = g[j][i] = (arr[i] & arr[j]) > 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (g[i][j] == 1)
            {
                g[i][j] = 0;
                res = min(res, bfs(g, i, j, n));
                g[i][j] = 1;
            }
        }
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