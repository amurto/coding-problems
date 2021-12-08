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

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

int solve()
{
    int n, pre = 1;
    cin >> n;
    vector<int> arr(n + 1), dp(n + 1);
    map<ll, int> last;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1ll * arr[i];
        dp[i] = pre;
        if (last[sum] > 0)
            pre = add(pre, -dp[last[sum]]);
        pre = add(pre, dp[i]);
        last[sum] = i;
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}