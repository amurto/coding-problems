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

const ll inf = 1e9 + 5;
ll solve()
{
    int n, m, g = 0;
    cin >> n >> m;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        g = __gcd(g, val);
    }
    vector<ll> col(g), mn(g, inf), sum(g);
    for (int i = 0; i < g; i++)
    {
        for (int j = i; j < n; j += g)
        {
            if (A[j] < 0)
                col[i] ^= 1;
            mn[i] = min(mn[i], abs(A[j]));
            sum[i] += abs(A[j]);
        }
    }
    vector<ll> dp(2);
    for (int i = 0; i < g; i++)
    {
        dp[col[i]] += sum[i];
        dp[col[i] ^ 1] += sum[i] - 2 * mn[i];
    }
    return max(dp[0], dp[1]);
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