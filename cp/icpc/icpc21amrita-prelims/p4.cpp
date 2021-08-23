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

const int K = 26;
ll solve()
{
    int n, q;
    cin >> n >> q;
    ll res = 0;
    vector<string> arr(n);
    vector<vector<ll>> pdp(K, vector<ll>(K));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int sz = arr[i].length();
        vector<vector<ll>> cdp(K, vector<ll>(K));
        for (int j = 0; j < K; j++)
        {
            for (int k = 0; k < sz; k++)
            {
                if (arr[i][k] - 'a' >= j)
                {
                    int cur = arr[i][k] - 'a';
                    ll b = 0;
                    for (int c = j; c <= cur; c++)
                        b = max(b, cdp[j][c]);
                    cdp[j][cur] = b + 1;
                    for (int c = cur + 1; c < K; c++)
                        cdp[j][c] = max(cdp[j][c], cdp[j][cur]);
                }
            }
        }
        for (int j = 0; j < K; j++)
            for (int k = j; k < K; k++)
                pdp[j][k] = max(pdp[j][k], cdp[j][k]);
    }
    int mx = min(K, q);
    vector<vector<ll>> dp(mx + 1, vector<ll>(K));
    for (int i = 1; i <= mx; i++)
    {
        for (int j = 0; j < K; j++)
            for (int k = 0; k < K; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1ll * pdp[k][j]);
        for (int j = 0; j < K; j++)
            res = max(res, dp[i][j] + 1ll * (q - i) * pdp[j][j]);
    }
    return res;
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