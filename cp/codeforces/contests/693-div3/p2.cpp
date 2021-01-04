#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
int dp[101][201];
int fd(vector<int> &arr, int cur, int req, int n)
{
    if (req == 0)
        return 1;
    if (req < 0)
        return 0;
    if (cur == n)
        return (req == 0);
    if (dp[cur][req] == -1)
        dp[cur][req] = fd(arr, cur + 1, req, n) || fd(arr, cur + 1, req - arr[cur], n);
    return dp[cur][req];
}
bool solve()
{
    memset(dp, -1, sizeof(dp));
    int n, v, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum % 2)
        return false;
    int req = sum / 2;
    return fd(arr, 0, req, n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}