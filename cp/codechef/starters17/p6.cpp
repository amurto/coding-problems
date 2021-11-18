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

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int solve()
{
    int n, res = 1;
    cin >> n;
    vector<int> arr(n), dp(1 << n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp[0] = 1;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int r = 0;
        for (int b = 0; b < n; b++)
            if ((mask >> b) & 1)
                r = b;
        dp[mask] = dp[mask ^ (1 << r)];
        for (int b = 0; b < r; b++)
            if ((!((mask >> b) & 1)) && arr[r] > arr[b])
                dp[mask] = add(dp[mask], dp[mask ^ (1 << r) ^ (1 << b)]);
        res = add(res, dp[mask]);
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