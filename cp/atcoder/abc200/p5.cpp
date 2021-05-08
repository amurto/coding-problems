#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 3e6 + 5;
void solve()
{
    int n, mx;
    ll k;
    cin >> n >> k;
    vector<vector<ll>> dp(3, vector<ll>(N + 1));
    for (int i = 1; i <= n; i++)
        dp[0][i]++;
    mx = n;
    for (int j = 1; j <= 2; j++)
    {
        for (int i = 1; i <= mx; i++)
        {
            dp[j][i + 1] += dp[j - 1][i];
            dp[j][min(i + n + 1, N)] -= dp[j - 1][i];
        }
        for (int i = 1; i <= N; i++)
        {
            dp[j][i] += dp[j][i - 1];
            if (dp[j][i] > 0)
                mx = i;
        }
    }
    for (int j = 0; j < 3; j++)
        for (int i = 1; i <= N; i++)
            dp[j][i] += dp[j][i - 1];
    vector<int> tmp;
    for (int j = 2; j >= 0; j--)
    {
        int low = 1, high = N, res = N, e = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (dp[j][mid] >= k)
            {
                res = min(res, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        low = 1, high = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
        }
        tmp.pb(res);
        k -= dp[j][res - 1];
    }

    for (int i = 0; i < 3; i++)
        cout << tmp[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}