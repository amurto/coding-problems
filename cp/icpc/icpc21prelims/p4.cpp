#ifdef amurto
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
int solve()
{
    int n, q;
    cin >> n >> q;
    vector<string> arr(n);
    vector<vector<int>> pdp(K, vector<int>(K));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int sz = arr[i].length();
        vector<vector<int>> cdp(K, vector<int>(K));
        for (int j = 0; j < sz; j++)
        {
            int cur = arr[i][j] - 'a';
            for (int k = cur; k >= 0; k--)
            {
                // cdp[k][cur]
                if (k == cur)
                    cdp[k][cur]++;
                else
                    cdp[k][cur] = max(cdp[k][cur - 1], cdp[k][cur]) + 1;
            }
        }
        for (int j = 0; j < K; j++)
            for (int k = j; k < K; k++)
                pdp[j][k] = max(pdp[j][k], cdp[j][k]);
    }
    vector<vector<int>> dp(q, vector<int>(K));
    for (int i = 0; i < q; i++)
        for (int j = 0; j < K; j++)
            for (int k = 0; k < K; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + pdp[k][j]);
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