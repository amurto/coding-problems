#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj1(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj1[a][b] = adj1[b][a] = 1;
    }
    vector<int> p(n), u(m), v(m);
    iota(p.begin(), p.end(), 1);
    for (int i = 0; i < m; i++)
        cin >> u[i] >> v[i];
    do
    {
        vector<vector<int>> adj2(n + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
            adj2[p[u[i] - 1]][p[v[i] - 1]] = adj2[p[v[i] - 1]][p[u[i] - 1]] = 1;
        bool pos = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (adj1[i][j] != adj2[i][j])
                    pos = false;
        if (pos)
            return true;
    } while (next_permutation(p.begin(), p.end()));
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}