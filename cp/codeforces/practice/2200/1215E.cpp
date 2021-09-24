// https://codeforces.com/contest/1215/problem/E
// Marbles

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = *max_element(arr.begin(), arr.end());
    vector<ll> dp(1 << mx, inf), st(mx);
    vector<vector<ll>> g(mx, vector<ll>(mx));
    for (int x : arr)
    {
        for (int j = 0; j < mx; j++)
            if (j != x - 1)
                g[x - 1][j] += st[j];
        st[x - 1]++;
    }
    dp[0] = 0;
    for (int mask = 1; mask < (1 << mx); mask++)
    {
        for (int j = 0; j < mx; j++)
        {
            if ((mask >> j) & 1)
            {
                ll req = 0;
                for (int k = 0; k < mx; k++)
                    if (k != j && !((mask >> k) & 1))
                        req += g[j][k];
                dp[mask] = min(dp[mask], dp[mask ^ (1 << j)] + req);
            }
        }
    }
    return dp[(1 << mx) - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}