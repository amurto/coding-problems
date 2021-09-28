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
    int n, m, k, stars = 0;
    cin >> n >> m >> k;
    vector<string> grid(n), vis(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        vis[i] = string(m, '.');
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            stars += (grid[i][j] == '*');
    if (stars == 0)
        return true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '*')
            {
                int r = i - 1, c1 = j - 1, c2 = j + 1;
                while (r >= 0 && c1 >= 0 && c2 < m && grid[r][c1] == '*' && grid[r][c2] == '*')
                {
                    r--;
                    c1--;
                    c2++;
                }
                if (i-r - 1 >= k)
                {
                    vis[i][j] = '*';
                    r = i - 1;
                    c1 = j - 1;
                    c2 = j + 1;
                    while (r >= 0 && c1 >= 0 && c2 < m && grid[r][c1] == '*' && grid[r][c2] == '*')
                    {
                        vis[r][c1] = '*';
                        vis[r][c2] = '*';
                        r--;
                        c1--;
                        c2++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (grid[i] != vis[i])
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