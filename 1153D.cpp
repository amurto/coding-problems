// https://codeforces.com/contest/1153/problem/D
// Serval and Rooted Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dfs(vector<vector<int>> &g, vector<int> &op, int cur, int last, int k)
{
    if (g[cur].size() == 1 && g[cur][0] == last)
        return k;
    int mx = 0, sum = 0;
    for (int e : g[cur])
    {
        if (e != last)
        {
            int x = dfs(g, op, e, cur, k);
            mx = max(mx, x);
            sum += k - mx + 1;
        }
    }
    return op[cur] == 0 ? k - sum + 1 : mx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, k = 0;
    cin >> n;
    vector<int> op(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> op[i];
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        g[x].pb(i);
        g[i].pb(x);
    }
    for (int i = 2; i <= n; i++)
        if (g[i].size() == 1)
            k++;
    cout << dfs(g, op, 1, -1, k) << "\n";
    return 0;
}