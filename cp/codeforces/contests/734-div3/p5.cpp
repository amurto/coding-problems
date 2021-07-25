#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void rotateGrid(vector<vector<char>> &grid, int &n, int &m)
{
    vector<vector<char>> mat(m, vector<char>(n));
    for (int j = 0, a = 0; j < m; j++, a++)
        for (int i = n - 1, b = 0; i >= 0; i--, b++)
            mat[a][b] = grid[i][j];
    grid = mat;
    swap(n, m);
}

void displayGrid(vector<vector<char>> &grid, int &n, int &m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << "\n";
    }
}

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    int v = (n * m) / 2 - h;
    string chs = "";
    for (char ch = 'a'; ch <= 'z'; ch++)
        chs.pb(ch);
    // try to place all horizontal on m
    for (int is_rotate = 0; is_rotate < 2; is_rotate++)
    {
        if (is_rotate)
        {
            swap(n, m);
            swap(h, v);
        }
        if ((m & 1) || (n % 2 == 1 && h * 2 < m))
            continue;
        vector<vector<char>> grid(n, vector<char>(m));
        string wx = "wx";
        for (int j = 0; j < m; j++)
            for (int i = 1, p = (j % 2); i < n; i += 2, p ^= 1)
                grid[i - 1][j] = grid[i][j] = wx[p];
        int rem = h;
        string yz = "yz";
        if (n % 2 == 1)
        {
            for (int j = 1, c = 0; j < m; j += 2, c++)
                grid[n - 1][j - 1] = grid[n - 1][j] = yz[c % 2];
            rem -= (m / 2);
        }
        if (rem & 1)
            continue;
        int r = n;
        if (r & 1)
            r--;
        for (int j = 1, f = 0; rem > 0 && j < m; j += 2, f ^= 1)
            for (int i = 0, c = f; rem > 0 && i < r; i++, c++, rem--)
                grid[i][j - 1] = grid[i][j] = chs[c % 22];
        if (is_rotate)
            rotateGrid(grid, n, m);
        cout << "YES\n";
        displayGrid(grid, n, m);
        return;
    }
    cout << "NO\n";
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