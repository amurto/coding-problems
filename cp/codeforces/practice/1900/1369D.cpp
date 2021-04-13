// https://codeforces.com/contest/1369/problem/D
// TediousLee

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 2e6 + 5;

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

int dp[N];
void init()
{
    dp[0] = dp[1] = dp[2] = 0;
    for (int i = 3; i < N; i++)
        dp[i] = add(add(mul(2, dp[i - 2]), dp[i - 1]), i % 3 == 0 ? 4 : 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}