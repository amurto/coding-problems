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

const int N = 1e6 + 1;
const double E = 0.5772156649;

double dp[N];
double f(ll den)
{
    return 1.0 / (1.0 * den);
}

void init()
{
    dp[0] = 0;
    for (int i = 1; i < N; i++)
        dp[i] = dp[i - 1] + f(i);
}

double solve()
{
    ll n;
    cin >> n;
    return (n < N) ? dp[n] : log(n) + E + f(2 * n) - (f(12) * f(n) * f(n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    init();
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}