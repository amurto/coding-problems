#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back

ld solve()
{
    int n;
    cin >> n;
    vector<ld> fac(n + 1), dp(n + 1);
    fac[0] = fac[1] = 1.0;
    for (int i = 2; i <= n; i++)
        fac[i] = fac[i - 1] / (1.0 * i);
    dp[1] = fac[n];
    for (int i = 2; i <= n; i++)
    {
        if (i > 1760)
            dp[i] = dp[i - 1] * i;
        else
            dp[i] = dp[i - 1] * i + fac[n] / fac[i - 1];
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(18);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}