// https://codeforces.com/contest/1272/problem/E
// Nearest Opposite Parity

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int inf = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i - arr[i] > 0)
            g[i - arr[i]].pb(i);
        if (i + arr[i] <= n)
            g[i + arr[i]].pb(i);
    }
    queue<pii> q;
    vector<vector<bool>> vis(n + 1, vector<bool>(2));
    vector<vector<int>> dis(n + 1, vector<int>(2, inf));
    for (int i = 1; i <= n; i++)
    {
        q.push({i, arr[i] % 2});
        vis[i][arr[i] % 2] = true;
        dis[i][arr[i] % 2] = 0;
    }
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            pii cur = q.front();
            q.pop();
            for (int e : g[cur.first])
            {
                if (!vis[e][cur.second])
                {
                    dis[e][cur.second] = dis[cur.first][cur.second] + 1;
                    vis[e][cur.second] = true;
                    q.push({e, cur.second});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        dis[i][(arr[i] % 2) ^ 1] == inf ? cout << "-1 " : cout << dis[i][(arr[i] % 2) ^ 1] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}