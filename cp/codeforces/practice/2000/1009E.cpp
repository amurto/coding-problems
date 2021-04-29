// https://codeforces.com/contest/1009/problem/E
// Intercity Travelling

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

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), dp(n + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int pre = arr[0];
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = add(add(mul(dp[i - 1], 2), pre), arr[i]);
        pre = add(mul(pre, 2), arr[i]);
    }
    return dp[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}