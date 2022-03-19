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
    int n;
    cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    int m = n;
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;
    for (int j = 1; j < m; j++)
    {
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            p ^= dp[j - 1][i];
            dp[j][i] = p;
        }
    }
    for (int j = 0; j < m; j++)
    {
        d(dp[j]);
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}