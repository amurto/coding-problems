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

const int N = 2e5 + 5;
int dp[N][21];
void init()
{
    for (int b = 0; b < 21; b++)
        dp[0][b] = 0;
    for (int i = 1; i < N; i++)
    {
        for (int b = 0; b < 21; b++)
        {
            dp[i][b] = dp[i - 1][b];
            if ((i >> b) & 1)
                dp[i][b]++;
        }
    }
}

int solve()
{
    int l, r;
    cin >> l >> r;
    int n = r - l + 1, res = 0;
    for (int i = 0; i < 21; i++)
        res = max(res, dp[r][i] - dp[l - 1][i]);
    return n - res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}