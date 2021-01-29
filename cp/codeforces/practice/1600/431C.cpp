// https://codeforces.com/contest/431/problem/C
// k-Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;
int add(int x, int y)
{
    x += y;
    while (x > 0)
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
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[n][1] = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 1; j <= k; j++)
            for (int f = 0; f < 2; f++)
                if (i + j <= n)
                    dp[i][f] = add(dp[i][f], dp[i + j][f || j >= d]);
    cout << dp[0][0] << "\n";
    return 0;
}