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

bool is_valid(vector<vector<char>> &grid, string &str, int n)
{
    for (int i = 0; i < n; i++)
    {
        int w = 0, dw = 0, l = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                if (grid[i][j] == '+')
                    w++;
                else if (grid[i][j] == '=')
                    dw++;
                else
                    l++;
            }
        }
        if (str[i] == '1')
        {
            if (l > 0)
                return false;
        }
        else
        {
            if (w == 0)
                return false;
        }
    }
    return true;
}

void display(vector<vector<char>> &grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j];
        cout << "\n";
    }
}

void solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<vector<char>> grid(n, vector<char>(n, '0'));
    for (int i = 0; i < n; i++)
        grid[i][i] = 'X';
    vector<vector<int>> ids(2);
    for (int i = 0; i < n; i++)
        ids[str[i] - '1'].pb(i);

    if (!ids[0].empty())
    {
        int sz = ids[0].size();
        for (int x : ids[0])
            for (int y : ids[0])
                if (x != y)
                    grid[x][y] = grid[y][x] = '=';
        for (int x : ids[0])
        {
            for (int j = 0; j < n; j++)
            {
                if (x != j && grid[x][j] == '0')
                {
                    grid[x][j] = '+';
                    grid[j][x] = '-';
                }
            }
        }
    }
    if (!ids[1].empty())
    {
        int sz = ids[1].size();
        if (sz == 1)
        {
            cout << "NO\n";
            return;
        }
        for (int i = 0; i < sz; i++)
        {
            int nxt = i + 1;
            if (nxt == sz)
                nxt = 0;
            int cur = ids[1][i], j = ids[1][nxt];
            grid[cur][j] = '+';
            grid[j][cur] = '-';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '0')
            {
                grid[i][j] = '+';
                grid[j][i] = '-';
            }
        }
    }
    if (!is_valid(grid, str, n))
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    display(grid, n);
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