#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e9 + 5;
ll solve()
{
    int n, c;
    ll x;
    cin >> n;
    vector<vector<ll>> arr(n + 2, vector<ll>(2)), dp(n + 2, vector<ll>(2));
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
    int j = n + 1;
    for (int i = n; i >= 0; i--)
    {
        if (arr[i][0] == inf)
            continue;
        dp[i][0] = min(abs(arr[i][0] - arr[j][1]) + abs(arr[j][1] - arr[j][0]) + dp[j][0], abs(arr[i][0] - arr[j][0]) + abs(arr[j][0] - arr[j][1]) + dp[j][1]);
        dp[i][1] = min(abs(arr[i][1] - arr[j][1]) + abs(arr[j][1] - arr[j][0]) + dp[j][0], abs(arr[i][1] - arr[j][0]) + abs(arr[j][0] - arr[j][1]) + dp[j][1]);
        j = i;
    }
    return min(dp[0][0], dp[0][1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}