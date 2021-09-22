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

const int inf = 1e9 + 7;

int ap(int a, int n)
{
    return (n * (2 * a + n - 1)) / 2;
}

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m = (k + 1) / 2;
    vector<int> cnt(1 << k), dp(1 << k, inf);
    for (int i = 0; i < (1 << k); i++)
        cnt[i] = __builtin_popcount(i);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int v = arr[i] - 1;
        for (int mask = 0; mask < (1 << k); mask++)
        {
            if (!((mask >> v) & 1) && dp[mask] < inf)
            {
                int nmask = mask | (1 << v), val = dp[mask];
                for (int j = v + 1; j < k; j++)
                    if ((mask >> j) & 1)
                        val++;
                if (cnt[nmask] == m)
                    val += (i * m) - (i * (k - m)) - ap(0, m) - ap(1, k - m);
                if (cnt[nmask] <= m)
                    val -= i;
                else
                    val += i;
                dp[nmask] = min(dp[nmask], val);
            }
        }
    }
    return dp[(1 << k) - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}