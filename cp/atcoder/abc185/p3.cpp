#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int L;
    cin >> L;
    vector<vector<ll>> dp(L, vector<ll>(12));
    for (int i = 0; i < L; i++)
        dp[i][0] = 1;
    for (int i = 1; i < L; i++)
        for (int j = 1; j < 12; j++)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    cout << dp[L - 1][11] << "\n";
    return 0;
}