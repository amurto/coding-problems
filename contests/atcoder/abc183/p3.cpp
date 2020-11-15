#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 9;
ll T[N][N];
bool vis[N];

ll dfs(int cur, ll time, int len, int n, ll k)
{
    if (len == n)
    {
        if (time + T[cur][1] == k)
            return 1;
        return 0;
    }
    ll res = 0;
    vis[cur] = true;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        res += dfs(i, time + T[cur][i], len + 1, n, k);
    }
    vis[cur] = false;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> T[i][j];
    memset(vis, false, sizeof(vis));
    cout << dfs(1, 0, 1, n, k) << "\n";
    return 0;
}