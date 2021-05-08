#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 3e6 + 5;
void dfs(vector<vector<ll>> &dp, int n, ll k)
{
    int low = 1, high = 3 * n, sum = 3 * n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (dp[2][mid] >= k)
        {
            sum = min(sum, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    k -= dp[2][sum - 1];
    vector<int> tmp(3);
    for (int j = 0, u = 1; j < 2; j++, u--)
    {
        ll pre = 0, rem = 0;
        int last = 1;
        int mn = max(1, sum - u * n), mx = min(n, sum - u * 1);
        for (int i = mn; pre < k && i <= mx; i++)
        {
            rem += pre;
            pre += dp[u][sum - i];
            last = i;
        }
        k -= rem;
        sum -= last;
        tmp[j] = last;
        // cout << last << " " << sum << " " << k << "\n";
        // cout << k << "\n";
    }
    tmp[2] = sum;
    for (int t : tmp)
        cout << t << " ";
    cout << "\n";
}

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
    for (int i = 1; i <= N; i++)
        dp[2][i] += dp[2][i - 1];
    // dfs(dp, n, k);
    for (ll i = 1; i <= 1ll * n * n * n; i++)
    {
        cout << i << " ";
        dfs(dp, n, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}