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

bool is_power(ll x) {
    
}
bool solve()
{
    ll n;
    int k = 5;
    cin >> n;
    if (n > 100)
        return n % 2 == 0;
    k = n + 1;
    vector<int> dp(k);
    for (int i = 1; i < k; i++)
    {
        if (dp[i - 1] == 0)
            dp[i] = 1;
        for (int j = 2; j <= i; j *= 2)
            if (i % j == 0 && dp[i / j] == 0)
                dp[i] = 1;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << i << " -> " << dp[i] << "\n";
    // int w = 0;
    // if (n < k)
    //     w = dp[n];
    // else
    //     w = (n % 2 == 0);
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Alice\n" : cout << "Bob\n";
    return 0;
}