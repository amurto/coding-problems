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

int solve()
{
    int n, k, res = 1;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int mn = *min_element(arr.begin() + 1, arr.end()), mx = *max_element(arr.begin(), arr.end());
    vector<vector<int>> dp(mx + 1, vector<int>(k + 1, -1)), st(k + 1, vector<int>(2));
    if (mn == mx)
        return n;
    for (int i = 1; i <= n; i++)
        dp[arr[i]][0] = 0;
    st[0][0] = mx;
    st[0][1] = mn;
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 0; j--)
        {
            if (dp[arr[i]][j] >= 0)
                dp[arr[i]][j] = 1 + dp[arr[i]][j];
            if (j > 0)
            {
                int t = 0;
                if (st[j - 1][t] == arr[i])
                    t++;
                if (st[j - 1][t] > 0)
                    dp[arr[i]][j] = max(dp[arr[i]][j], 1 + dp[st[j - 1][t]][j - 1]);
            }
            if (st[j][0] != arr[i] && st[j][1] != arr[i])
                if (dp[arr[i]][j] > dp[st[j][1]][j])
                    st[j][1] = arr[i];
            if (dp[st[j][1]][j] > dp[st[j][0]][j])
                swap(st[j][0], st[j][1]);
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            res = max(res, dp[arr[i]][j]);
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