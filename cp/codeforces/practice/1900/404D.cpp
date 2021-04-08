// https://codeforces.com/contest/404/problem/D
// Minesweeper 1D

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mask(char ch)
{
    if (ch == '*')
        return 2;
    return ch - '0';
}

int solve()
{
    string str;
    cin >> str;
    int n = str.length();
    if (n == 1)
    {
        if (str[0] == '?')
            return 2;
        else if (str[0] == '*' || str[0] == '0')
            return 1;
        else
            return 0;
    }
    if (str[0] == '2')
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(3));
    dp[n][0] = dp[n][2] = 1;
    for (int i = n - 1; i > 0; i--)
    {
        for (int last = 0; last < 3; last++)
        {
            int res = 0;
            char ch = str[i];
            if (ch == '?')
            {
                if (last == 0)
                    res = add(res, add(dp[i + 1][0], dp[i + 1][1]));
                else if (last == 1)
                    res = add(res, dp[i + 1][2]);
                else
                    res = add(res, add(dp[i + 1][0], add(dp[i + 1][1], dp[i + 1][2])));
            }
            else
            {
                if (last == 0)
                    res = (ch == '*' || ch == '2') ? 0 : add(res, dp[i + 1][mask(ch)]);
                else if (last == 1)
                    res = (ch != '*') ? 0 : add(res, dp[i + 1][mask(ch)]);
                else
                {
                    if (ch != '0')
                        res = (ch == '*') ? add(res, dp[i + 1][mask(ch)]) : add(res, dp[i + 1][mask(ch) - 1]);
                }
            }
            dp[i][last] = res;
        }
    }
    return (str[0] == '?') ? add(dp[1][0], add(dp[1][1], dp[1][2])) : dp[1][mask(str[0])];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
}