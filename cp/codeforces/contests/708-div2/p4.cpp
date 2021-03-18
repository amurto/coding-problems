#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<int> tag(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> tag[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    vector<ll> dp(n + 1);
    ll res = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            if (tag[i] == tag[j])
                continue;
            ll dpi = dp[i], dpj = dp[j], d = abs(s[i] - s[j]);
            dp[i] = max(dp[i], dpj + d);
            dp[j] = max(dp[j], dpi + d);
            res = max({res, dp[i], dp[j]});
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}