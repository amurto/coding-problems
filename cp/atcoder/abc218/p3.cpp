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

void rotate_grid(vector<vector<char>> &grid, int &n)
{
    vector<vector<char>> mat(n, vector<char>(n));
    for (int j = 0, a = 0; j < n; j++, a++)
        for (int i = n - 1, b = 0; i >= 0; i--, b++)
            mat[a][b] = grid[i][j];
    grid = mat;
}

void translate_grid(vector<vector<char>> &grid, int &n)
{
    int mn_h = n, mn_v = n;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < n && grid[i][j] != '#')
            j++;
        mn_h = min(mn_h, j);
    }
    for (int j = 0; j < n; j++)
    {
        int i = 0;
        while (i < n && grid[i][j] != '#')
            i++;
        mn_v = min(mn_v, i);
    }
    vector<vector<char>> tmp(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i + mn_v < n && j + mn_h < n)
                tmp[i][j] = grid[i + mn_v][j + mn_h];
    swap(grid, tmp);
}

bool check_eq(vector<vector<char>> &s, vector<vector<char>> &t, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] != t[i][j])
                return false;
    return true;
}

void display_grid(vector<vector<char>> &grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j];
        cout << "\n";
    }
}
bool solve()
{
    int n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(n)), t(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> t[i][j];
    translate_grid(s, n);
    for (int r = 0; r < 4; r++)
    {
        translate_grid(t, n);
        if (check_eq(s, t, n))
            return true;
        rotate_grid(t, n);
    }
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