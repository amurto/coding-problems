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
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            int sum = 0;
            sum += (grid[i - 1][j - 1] - '0') + (grid[i - 1][j] - '0') + (grid[i][j - 1] - '0') + (grid[i][j] - '0');
            if (sum == 3)
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}