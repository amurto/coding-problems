#ifdef amurto
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            g[i][j] = g[j][i] = (__gcd(arr[i], arr[j]) > 1);
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2)));
    for (int i = 0; i < n; i++)
        dp[i][i][0] = dp[i][i][1] = 1;
    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, j++)
        {
            for (int k = i; dp[i][j][0] == 0 && k < j; k++)
                if (dp[i][k][0] + g[k][j] + dp[k][j - 1][1] == 3)
                    dp[i][j][0] = 1;
            for (int k = i + 1; dp[i][j][1] == 0 && k <= j; k++)
                if (dp[i + 1][k][0] + g[i][k] + dp[k][j][1] == 3)
                    dp[i][j][1] = 1;
        }
    }
    for (int i = 0; i < n; i++)
        if (dp[0][i][0] + dp[i][n - 1][1] == 2)
            return true;
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