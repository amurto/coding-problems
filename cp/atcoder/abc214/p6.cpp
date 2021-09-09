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

const int MOD = 1e9 + 7, K = 26;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int solve()
{
    string str;
    cin >> str;
    int n = str.length(), res = 1;
    str = "0" + str;
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int j = i - 1;
        while (j > 0 && str[j] != str[i])
            j--;
        if (j != 1)
            j = max(j - 1, 0);
        while (j < i - 1)
        {
            dp[i] = add(dp[i], dp[j]);
            j++;
        }
        res = add(res, dp[i]);
    }
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