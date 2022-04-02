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

const int MX = 6e5 + 5, inf = 1e9 + 7;
int dp[MX];
void init()
{
    dp[0] = 0;
    for (int i = 1; i < MX; i++)
        dp[i] = inf;
    int sum = 0;
    for (int i = 1, j = 2, t = 0; sum < MX; j++, t ^= 1)
    {
        int last = sum;
        if (last + (j - 1) / 2 + 1 < MX)
        {
            dp[last + (j - 1) / 2 + 1] = min(dp[last + (j - 1) / 2 + 1], j + 1);
        }
        for (int v = last + 1; v < min(sum + i, MX); v++)
            dp[v] = min(dp[v], dp[last] + 1 + dp[v - last]);

        sum += i;
        if (sum < MX)
            dp[sum] = j;
        if (t == 1)
            i++;
    }
}

bool solve()
{
    int n, k;
    cin >> n >> k;
    return dp[k] <= n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    // for (int i = 1; i <= 50; i++)
    //     cout << i << " -> " << dp[i] << "\n";
    // d(dp[MX - 1]);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}