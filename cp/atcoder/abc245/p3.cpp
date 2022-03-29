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

bool solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    vector<vector<bool>> dp(2, vector<bool>(n));
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    dp[0][n - 1] = dp[1][n - 1] = true;
    for (int i = n - 2; i >= 0; i--)
    {
        dp[0][i] = (abs(A[i] - A[i + 1]) <= k && dp[0][i + 1]) || (abs(A[i] - B[i + 1]) <= k && dp[1][i + 1]);
        dp[1][i] = (abs(B[i] - A[i + 1]) <= k && dp[0][i + 1]) || (abs(B[i] - B[i + 1]) <= k && dp[1][i + 1]);
    }
    return dp[0][0] || dp[1][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}