#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool seq(int a, int b, int c)
{
    return (b - a == c - b);
}

int cnt(vector<vector<int>> &grid)
{
    // cout << grid[1][1] << "\n";
    int res = 0;
    for (int i = 0; i < 3; i++)
        res += seq(grid[i][0], grid[i][1], grid[i][2]);
    for (int j = 0; j < 3; j++)
        res += seq(grid[0][j], grid[1][j], grid[2][j]);
    res += seq(grid[0][0], grid[1][1], grid[2][2]);
    res += seq(grid[0][2], grid[1][1], grid[2][0]);
    return res;
}

int mid(int a, int b)
{
    if (a > b)
        swap(a, b);
    return a + (b - a) / 2;
}
int solve()
{
    int res = 0;
    vector<vector<int>> grid(3, vector<int>(3, -1));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            cin >> grid[i][j];
        }
    }
    grid[1][1] = mid(grid[0][0], grid[2][2]);
    res = max(res, cnt(grid));
    grid[1][1] = mid(grid[0][2], grid[2][0]);
    res = max(res, cnt(grid));
    grid[1][1] = mid(grid[0][1], grid[2][1]);
    res = max(res, cnt(grid));
    grid[1][1] = mid(grid[1][0], grid[1][2]);
    res = max(res, cnt(grid));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}