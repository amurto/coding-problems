#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e9 + 5;
ll travel(vector<vector<ll>> &dp, vector<vector<ll>> &arr, int cur, int p, int n)
{
    ll x = arr[cur][p];
    if (cur == n + 1)
        return 0ll;
    if (dp[cur][p] == -1)
    {
        dp[cur][p] = 1e18;
        int j = cur + 1;
        while (arr[j][0] == inf)
            j++;
        dp[cur][p] = 1e18;
        // last -> first
        ll d1 = abs(x - arr[j][1]) + abs(arr[j][1] - arr[j][0]) + travel(dp, arr, j, 0, n);

        // first->last
        ll d2 = abs(x - arr[j][0]) + abs(arr[j][0] - arr[j][1]) + travel(dp, arr, j, 1, n);
        dp[cur][p] = min(d1, d2);
    }
    return dp[cur][p];
}

ll solve()
{
    int n, c;
    ll x;
    cin >> n;
    vector<vector<ll>> arr(n + 2, vector<ll>(2)), dp(n + 2, vector<ll>(2, -1));
    for (int i = 1; i <= n; i++)
    {
        arr[i][0] = inf;
        arr[i][1] = -inf;
    }
    arr[0][0] = arr[0][1] = arr[n + 1][0] = arr[n + 1][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> c;
        arr[c][0] = min(arr[c][0], x);
        arr[c][1] = max(arr[c][1], x);
    }
    return travel(arr, dp, 0, 0, n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}