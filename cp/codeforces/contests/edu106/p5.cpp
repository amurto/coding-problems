#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int solve()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n1 = str1.length(), n2 = str2.length(), res = 0;
    vector<vector<vector<vector<int>>>> dp(n1 + 1, vector<vector<vector<int>>>(n2 + 1, vector<vector<int>>(3, vector<int>(4))));
    for (int i = n1; i >= 0; i--)
    {
        for (int j = n2; j >= 0; j--)
        {
            for (int last = 2; last >= 0; last--)
            {
                int prev = 26;
                if (last == 0 && i > 0)
                    prev = str1[i - 1] - 'a';
                if (last == 1 && j > 0)
                    prev = str2[j - 1] - 'a';
                for (int k = 0; k < 4; k++)
                {
                    if (k == 3)
                        dp[i][j][last][k]++;
                    if (i < n1 && str1[i] - 'a' != prev)
                        dp[i][j][last][k] = add(dp[i][j][last][k], dp[i + 1][j][0][k | 1]);
                    if (j < n2 && str2[j] - 'a' != prev)
                        dp[i][j][last][k] = add(dp[i][j][last][k], dp[i][j + 1][1][k | 2]);
                }
            }
        }
    }
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            res = add(res, dp[i][j][2][0]);
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