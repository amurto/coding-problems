#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
const int N = 5001, inf = -6000;
int dp[N][N];

int LCS(string &str1, string &str2, int n, int m)
{
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] <= inf)
    {
        if (str1[n] == str2[m])
            dp[n][m] = 4 + LCS(str1, str2, n - 1, m - 1) - 2;
        else
            dp[n][m] = max(LCS(str1, str2, n - 1, m) - 1, LCS(str1, str2, n, m - 1) - 1);
    }
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string str1, str2;
    cin >> str1 >> str2;
    memset(dp, inf, sizeof(dp));
    cout << LCS(str1, str2, n - 1, m - 1) << "\n";
    return 0;
}