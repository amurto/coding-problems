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

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    x %= MOD;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    vector<vector<int>> rmx(n + 1, vector<int>(n + 1)), dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        rmx[i][i] = arr[i];
        for (int j = i + 1; j <= n; j++)
            rmx[i][j] = max(rmx[i][j - 1], arr[j]);
    }
    for (int i = 1; i <= n; i++)
    {
        vector<vector<int>> tdp = dp;
        for (int t = 1; t <= m - arr[i]; t++)
            for (int j = 1; j < i; j++)
                if (dp[t][j] > 0 && rmx[j][i] > max(arr[j], arr[i]))
                    tdp[t + arr[i]][i] = add(tdp[t + arr[i]][i], dp[t][j]);
        tdp[arr[i]][i] = add(tdp[arr[i]][i], 1);
        swap(dp, tdp);
    }
    for (int i = 1; i <= m; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            sum = add(sum, dp[i][j]);
        cout << sum << " ";
    }
    cout << "\n";
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