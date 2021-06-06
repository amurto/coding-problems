#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5, inf = 1e8;
int dp[105][N];

int dfs(vector<int> &arr, int cur, int cur_sum, int sum, int n)
{
    if (cur == n)
        return max(cur_sum, sum - cur_sum);
    if (dp[cur][cur_sum] == -1)
        dp[cur][cur_sum] = min(dfs(arr, cur + 1, cur_sum, sum, n), dfs(arr, cur + 1, cur_sum + arr[cur], sum, n));
    return dp[cur][cur_sum];
}

int solve()
{
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    memset(dp, -1, sizeof(dp));
    return dfs(arr, 0, 0, sum, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}