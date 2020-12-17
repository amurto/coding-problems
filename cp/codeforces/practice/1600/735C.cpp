// https://codeforces.com/contest/735/problem/C
// Tennis Championship

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    ll n;
    cin >> n;
    vector<ll> dp;
    dp.pb(2);
    dp.pb(3);
    int cur = 1;
    while (dp[cur] <= n)
    {
        dp.pb(dp[cur] + dp[cur - 1]);
        cur++;
    }
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}