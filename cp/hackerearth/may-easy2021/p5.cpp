#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 1005;
int dp[N][N][2];

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int odd(vector<int> &arr, int cur, int sum, int len, int k)
{
    if (len == k)
        return sum == 1;
    if (cur == arr.size())
        return 0;
    if (dp[cur][len][sum] == -1)
        dp[cur][len][sum] = add(odd(arr, cur + 1, sum, len, k), odd(arr, cur + 1, (sum + arr[cur]) % 2, len + 1, k));
    return dp[cur][len][sum];
}

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    return odd(arr, 0, 0, 0, k);
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