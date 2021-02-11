// https://codeforces.com/contest/106/problem/C
// Buns

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;
    vector<int> A(m), B(m), C(m), D(m);
    for (int i = 0; i < m; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = n; i >= 0; i--)
        dp[m][i] = (i / c0) * d0;
    for (int i = m - 1; i >= 0; i--)
        for (int j = n; j >= 0; j--)
            for (int k = 0; k * B[i] <= A[i] && k * C[i] <= j; k++)
                dp[i][j] = max(dp[i][j], k * D[i] + dp[i + 1][j - k * C[i]]);
    cout << dp[0][n] << "\n";
    return 0;
}