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

const ll inf = 2e18;
ll solve()
{
    int n;
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    vector<ll> dp(1 << n, inf);
    vector<vector<ll>> adj(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = x * abs(A[i] - B[j]);
    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int id = __builtin_popcount(mask) - 1, pre = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
                dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + adj[i][id] + y * pre);
            else
                pre++;
        }
    }
    return dp[(1 << n) - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}