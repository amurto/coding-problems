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
    int h, w, res = 0;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++)
        cin >> grid[i];
    vector<vector<int>> dp(h, vector<int>(w));
    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            if (grid[i][j] == '.')
            {
                dp[i][j] = 1;
                if (i + 1 < h && grid[i + 1][j] == '.')
                    dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
                if (j + 1 < w && grid[i][j + 1] == '.')
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
            }
        }
    }
    return dp[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}