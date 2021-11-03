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

const int N = 1e6 + 5;
int dp[N][5][5];
int solve()
{
    int n, m, res = 0, sz = 4;
    cin >> n >> m;
    vector<int> arr(n), cnt(m + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    for (int j = 0; j <= min(sz, cnt[1]); j++)
        dp[1][0][j] = (cnt[1] - j) / 3;
    for (int i = 2; i <= m; i++)
    {
        for (int j = 0; j <= min(cnt[i - 1], sz); j++)
        {
            for (int l = 0; l <= min(cnt[i - 2], sz); l++)
            {
                if (dp[i - 1][l][j] >= 0)
                {
                    // dp[i-1][l][j] -> dp[i][x][y]
                    for (int x = 0; x <= j; x++)
                    {
                        for (int y = 0; y <= min(sz, cnt[i]); y++)
                        {
                            // we use {l, j-x, cnt[i]-y}
                            int mn = min(l, min(j - x, cnt[i] - y));
                            for (int t = 0; t <= mn; t++)
                                dp[i][x][y] = max(dp[i][x][y], dp[i - 1][l][j] + t + (cnt[i] - y - t) / 3);
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= sz; j++)
            for (int k = 0; k <= sz; k++)
                res = max(res, dp[i][j][k]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}