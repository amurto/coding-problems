#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = -1e7;
int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(n, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = dp[0];
        dp[0] = max(dp[0], 1 + dp[arr[i]]);
        dp[arr[i]] = max(dp[arr[i]], 1 + temp);
    }
    return n - dp[0];
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