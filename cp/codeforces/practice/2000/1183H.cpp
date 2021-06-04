// https://codeforces.com/contest/1183/problem/H
// Subsequences (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    ll k, cost = 0;
    string str;
    cin >> n >> k >> str;
    vector<vector<ll>> dp(26, vector<ll>(n + 1));
    for (int i = 0; i < n; i++)
    {
        int cur = str[i] - 'a';
        for (int j = i + 1; j > 1; j--)
        {
            ll v = 0;
            for (int l = 0; l < 26; l++)
                v += dp[l][j - 1];
            dp[cur][j] = v;
        }
        if (dp[cur][1] == 0)
            dp[cur][1]++;
    }
    vector<ll> sum(n + 1);
    sum[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            sum[i] += dp[j][i];
    for (int i = n; k > 0 && i >= 0; i--)
    {
        if (sum[i] >= k)
        {
            cost += k * (n - i);
            k = 0;
        }
        else
        {
            cost += sum[i] * (n - i);
            k -= sum[i];
        }
    }
    return k > 0 ? -1 : cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}