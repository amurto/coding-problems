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
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] - grid[i - 1][j] != 7)
                return false;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            if (grid[i][j] - grid[i][j - 1] != 1)
                return false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
            if (grid[i][j] % 7 == 0)
                return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}