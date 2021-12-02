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

const ll inf = 1e18;
ll solve()
{
    int n;
    cin >> n;
    ll res = inf;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    // 0 and 1 have same color
    vector<vector<ll>> dp1(n + 1, vector<ll>(2, inf)), dp2(n + 1, vector<ll>(2, inf));
    dp1[1][0] = a[1];
    for (int i = 2; i <= n; i++)
    {
        dp1[i][0] = min(dp1[i][0], min(dp1[i - 1][0] + a[i] + b[i - 1], dp1[i - 1][1] + a[i]));
        dp1[i][1] = min(dp1[i][1], min(dp1[i - 1][0], dp1[i - 1][1] + b[i - 1]));
    }
    dp1[n][0] += b[n];
    res = min(res, min(dp1[n][0], dp1[n][1]));
    // 0 and 1 have different color
    dp2[1][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp2[i][0] = min(dp2[i][0], min(dp2[i - 1][0] + a[i] + b[i - 1], dp2[i - 1][1] + a[i]));
        dp2[i][1] = min(dp2[i][1], min(dp2[i - 1][0], dp2[i - 1][1] + b[i - 1]));
    }
    dp2[n][1] += b[n];
    res = min(res, min(dp2[n][0], dp2[n][1]));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}