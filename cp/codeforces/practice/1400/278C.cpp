// https://codeforces.com/contest/278/problem/C
// Learning Languages

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 101;
vector<vector<int>> g(N, vector<int>(N));
vector<bool> pres(N), vis(N);
int dfs(int cur, int m)
{
    int res = 1;
    vis[cur] = true;
    for (int i = 1; i <= m; i++)
        if (g[cur][i] && !vis[i])
            res += dfs(i, m);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, sz, e = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> sz;
        if (sz == 0)
        {
            e++;
            continue;
        }
        vector<int> arr(sz);
        for (int j = 0; j < sz; j++)
        {
            cin >> arr[j];
            pres[arr[j]] = true;
        }
        for (int j = 0; j < sz; j++)
            for (int k = j + 1; k < sz; k++)
                g[arr[j]][arr[k]] = g[arr[k]][arr[j]] = 1;
    }
    int res = 0;
    for (int i = 1; i <= m; i++)
    {
        if (pres[i] && !vis[i])
        {
            res++;
            dfs(i, m);
        }
    }
    res = max(res - 1, 0);
    cout << res + e << "\n";
    return 0;
}