// https://codeforces.com/contest/706/problem/C
// Hard problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e17;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<string> s(n), r(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, inf));
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i > 0; i--)
    {
        if (s[i - 1].compare(s[i]) <= 0)
            dp[i][0] = min(dp[i][0], dp[i + 1][0]);
        if (s[i - 1].compare(r[i]) <= 0)
            dp[i][0] = min(dp[i][0], c[i] + dp[i + 1][1]);
        if (r[i - 1].compare(s[i]) <= 0)
            dp[i][1] = min(dp[i][1], dp[i + 1][0]);
        if (r[i - 1].compare(r[i]) <= 0)
            dp[i][1] = min(dp[i][1], c[i] + dp[i + 1][1]);
    }
    dp[0][0] = min(dp[1][0], c[0] + dp[1][1]);
    dp[0][0] >= inf ? cout << "-1\n" : cout << dp[0][0] << "\n";
    return 0;
}