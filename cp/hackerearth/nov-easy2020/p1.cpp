// https://www.hackerearth.com/problem/algorithm/zero-sum-array-8bfe2f4e/
// Zero-sum array

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e7;

int zsa(vector<vector<int>> &dp, vector<int> &arr, int cur, int rem)
{
    if (rem == 0)
        return 0;
    if (cur == arr.size())
        return inf;
    if (dp[cur][rem] == -1)
    {
        int c = inf;
        if (rem - arr[cur] >= 0)
            c = 1 + zsa(dp, arr, cur + 1, rem - arr[cur]);
        int nc = zsa(dp, arr, cur + 1, rem);
        dp[cur][rem] = min(c, nc);
    }
    return dp[cur][rem];
}

int solve()
{
    int n, sum = 0, moves = 0;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum & 1)
        return -1;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    int ans = zsa(dp, arr, 0, sum / 2);
    if (ans == inf)
        return -1;
    else
        return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        cout << solve() << "\n";
    }
    return 0;
}