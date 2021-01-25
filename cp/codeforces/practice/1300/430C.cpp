// https://codeforces.com/contest/430/problem/C
// Xor-tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 1;
vector<int> g[N], res;
vector<bool> vis(N);
int mark[N], req[N];

void dfs(int cur, int f1, int f2)
{
    vis[cur] = true;
    int val = mark[cur] ^ f1;
    if (val != req[cur])
    {
        res.pb(cur);
        f1 ^= 1;
    }
    for (int e : g[cur])
        if (!vis[e])
            dfs(e, f2, f1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> mark[i];
    for (int i = 1; i <= n; i++)
        cin >> req[i];
    dfs(1, 0, 0);
    cout << res.size() << "\n";
    for (int r : res)
        cout << r << "\n";
    return 0;
}