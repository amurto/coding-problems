// https://codeforces.com/contest/437/problem/C
// The Child and Toy

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    vector<int> f(n), arr(n);
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        arr[i] = i;
    }
    auto cmp = [&](int &v1, int &v2) { return f[v1] > f[v2]; };
    sort(arr.begin(), arr.end(), cmp);
    while (m-- > 0)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u][v] = g[v][u] = 1;
    }
    int res = 0;
    for (int e: arr)
    {
        for (int i = 0; i < n; i++)
        {
            if (g[e][i] == 1)
            {
                res += f[i];
                g[e][i] = g[i][e] = 0;
            }
        }
    }
    cout << res << "\n";
    return 0;
}