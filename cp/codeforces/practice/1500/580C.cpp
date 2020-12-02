// https://codeforces.com/contest/580/problem/C
// Kefa and Park

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 1;
vector<int> c(N);
vector<vector<int>> tree(N);
int dfs(int v, int m, int par, int cur)
{
    if (c[cur] == 1)
        v++;
    else
        v = 0;
    if (v > m)
        return 0;
    if (tree[cur].size() == 1 && tree[cur][0] == par)
        return 1;
    int res = 0;
    for (int child : tree[cur])
    {
        if (child == par)
            continue;
        res += dfs(v, m, cur, child);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    cout << dfs(0, m, 0, 1) << "\n";
    return 0;
}
