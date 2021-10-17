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

void solve()
{
    int n, m, q, j1, j2;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<int> pre(m);
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (grid[i - 1][j] == 'X' && grid[i][j - 1] == 'X')
                pre[j] = 1;
    for (int j = 1; j < m; j++)
        pre[j] += pre[j - 1];
    cin >> q;
    for (int itr = 0; itr < q; itr++)
    {
        cin >> j1 >> j2;
        j1--;
        j2--;
        pre[j2] - pre[j1] > 0 ? cout << "NO\n" : cout << "YES\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}