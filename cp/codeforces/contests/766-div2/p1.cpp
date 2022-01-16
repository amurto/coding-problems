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

int solve()
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--;
    c--;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    if (grid[r][c] == 'B')
        return 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'W')
                cnt++;
    if (cnt == n * m)
        return -1;
    for (int i = 0; i < n; i++)
        if (grid[i][c] == 'B')
            return 1;
    for (int j = 0; j < m; j++)
        if (grid[r][j] == 'B')
            return 1;
    return 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}