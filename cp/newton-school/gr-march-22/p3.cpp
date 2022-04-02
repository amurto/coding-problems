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
    vector<vector<ll>> grid(n, vector<ll>(m)), rem(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    rem[0][0] = grid[0][0];
    if (n == 1 && m == 1)
        return true;
    for (int t = 1; t < n + m - 1; t++)
    {
        for (int i = min(n - 1, t); i >= 0; i--)
        {
            int j = t - i;
            if (j < m)
            {
                ll req = grid[i][j];
                // i,j-1
                if (req > 0 && j - 1 >= 0)
                {
                    ll sub = min(req, rem[i][j - 1]);
                    rem[i][j - 1] -= sub;
                    req -= sub;
                }
                // i-1,j
                if (req > 0 && i - 1 >= 0)
                {
                    ll sub = min(req, rem[i - 1][j]);
                    rem[i - 1][j] -= sub;
                    req -= sub;
                }
                if (req > 0)
                    return false;
                rem[i][j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i + j < n + m - 2)
                if (rem[i][j] > 0)
                    return false;
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