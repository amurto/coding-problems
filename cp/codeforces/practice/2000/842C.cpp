// https://codeforces.com/problemset/problem/842/C
// Ilya And The Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N], divs[N];
int arr[N], par[N], dp[N][2], st[N];

void init()
{
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divs[j].pb(i);
    for (int i = 1; i < N; i++)
        st[i] = 0;
}

void dfs(int cur, int last, int d)
{
    par[cur] = last;
    for (int div : divs[arr[cur]])
        st[div]++;
    for (int div : divs[arr[cur]])
    {
        if (st[div] == d)
            dp[cur][0] = max(dp[cur][0], div);
        if (st[div] == d - 1)
            dp[cur][1] = max(dp[cur][1], div);
    }
    dp[cur][1] = max(dp[cur][1], dp[par[cur]][0]);
    for (int e : g[cur])
        if (e != last)
            dfs(e, cur, d + 1);
    for (int div : divs[arr[cur]])
        st[div]--;
}

void solve()
{
    int n, u, v;
    cin >> n;
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++)
        cout << max(dp[i][0], dp[i][1]) << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}