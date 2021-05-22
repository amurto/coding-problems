#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int a, b, n;
    string str;
    ll k;
    cin >> a >> b >> k;
    n = a + b;
    vector<vector<ll>> dp(a + 1, vector<ll>(b + 1));
    dp[0][0] = 1;
    for (int i = 0; i <= a; i++)
        dp[i][0] = 1;
    for (int i = 0; i <= b; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    int remA = a, remB = b, cur = 0;
    while (remA > 0 && remB > 0 && cur < n)
    {
        if (k <= dp[remA - 1][remB])
        {
            str.pb('a');
            remA--;
        }
        else
        {
            str.pb('b');
            k -= dp[remA - 1][remB];
            remB--;
        }
        cur++;
    }
    while (remA > 0)
    {
        str.pb('a');
        remA--;
    }
    while (remB > 0)
    {
        str.pb('b');
        remB--;
    }
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}