// https://codeforces.com/contest/1324/problem/F
// Maximum White Subtree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int dfs(vector<vector<int>> &g, vector<int> &arr, vector<int> &st, int cur, int last)
{
    st[cur] = arr[cur];
    if (st[cur] == 0)
        st[cur]--;
    if (g[cur].size() == 1 && g[cur][0] == last)
        return max(0, st[cur]);
    for (int e : g[cur])
    {
        if (e == last)
            continue;
        int ret = dfs(g, arr, st, e, cur);
        if (ret > 0)
            st[cur] += ret;
    }
    return max(0, st[cur]);
}

void traverse(vector<vector<int>> &g, vector<int> &arr, vector<int> &st, int sum, int cur, int last)
{
    arr[cur] = st[cur] + sum;
    for (int e : g[cur])
        if (e != last)
            traverse(g, arr, st, max(0, st[cur] - max(0, st[e]) + sum), e, cur);
}

void solve()
{
    int n, u, v;
    cin >> n;
    vector<int> arr(n + 1), st(n + 1), res(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(g, arr, st, 1, -1);
    traverse(g, arr, st, 0, 1, -1);
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}