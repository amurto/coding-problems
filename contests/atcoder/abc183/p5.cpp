#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;
int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];

    int dp[h + 1][w + 1], row[h + 1][w + 1], col[h + 1][w + 1], diag[h + 1][w + 1];
    memset(dp, 0, sizeof(dp));
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(diag, 0, sizeof(diag));

    dp[h - 1][w - 1] = row[h - 1][w - 1] = col[h - 1][w - 1] = diag[h - 1][w - 1] = 1;
    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            if ((i == h - 1 && j == w - 1) || grid[i][j] == '#')
                continue;
            row[i][j] = row[i + 1][j];
            dp[i][j] = add(dp[i][j], row[i][j]);
            col[i][j] = col[i][j + 1];
            dp[i][j] = add(dp[i][j], col[i][j]);
            diag[i][j] = diag[i + 1][j + 1];
            dp[i][j] = add(dp[i][j], diag[i][j]);
            row[i][j] = add(row[i][j], dp[i][j]);
            col[i][j] = add(col[i][j], dp[i][j]);
            diag[i][j] = add(diag[i][j], dp[i][j]);
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cout << col[i][j] << " ";
        cout << "\n";
    }
    cout << dp[0][0] << "\n";
    return 0;
}