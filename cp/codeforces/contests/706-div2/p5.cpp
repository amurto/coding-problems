#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    int last = 0;
    for (int j = 0; j < m; j += 3)
    {
        for (int i = 0; i < n; i++)
            grid[i][j] = 'X';
        last = j;
        if (j > 0)
        {
            vector<int> cols = {j - 2, j - 1};
            bool con = false;
            for (int c = 0; !con && c < 2; c++)
            {
                for (int i = 0; !con && i < n; i++)
                {
                    if (grid[i][cols[c]] == 'X')
                    {
                        grid[i][cols[c ^ 1]] = 'X';
                        con = true;
                    }
                }
            }
            if (!con)
                grid[0][j - 2] = grid[0][j - 1] = 'X';
        }
    }
    if (last < m - 2)
    {
        for (int i = 0; i < n; i++)
        {
            if (grid[i][m - 1] == 'X')
                grid[i][m - 2] = 'X';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}