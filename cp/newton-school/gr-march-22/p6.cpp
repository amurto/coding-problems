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
const ll inf = 1e18 + 3;
ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<int> A(n);
    vector<ll> mn(N), dp(N, inf), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++)
    {
        if (dp[A[i]] == 0)
            A[i] = B[i];
        else
            dp[A[i]] = min(dp[A[i]], B[i]);
    }
    for (int i = 1; i < N; i++)
    {
        if (dp[i] > 0)
        {
            for (int j = i, t = 1; j < N; j += i, t++)
            {
                if (t >= i)
                    break;
                if (dp[t] > 0)
                    dp[j] = min(dp[j], dp[i] + dp[t]);
            }
        }
    }
    for (int i = 1; i < N; i++)
    {
        if (dp[i] >= inf)
            dp[i] = 0;
        res ^= dp[i];
    }
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