#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Check if a certain subset sum is possible
// O(n^2)
bool possible(vector<int> &arr, int n, int sum)
{
    if (sum % 2 == 1)
        return false;
    int h = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 5));
    for (int i = 0; i <= n; i++)
        dp[i][h] = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j <= sum - arr[i]; j++)
            dp[i][j] = dp[i + 1][j] || dp[i + 1][j + arr[i]];
    return dp[0][0];
}

void solve()
{
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (!possible(arr, n, sum))
    {
        cout << 0 << "\n";
        return;
    }
    for (int j = 0;; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] & 1)
            {
                cout << 1 << "\n";
                cout << i + 1 << "\n";
                return;
            }
        }
        for (int i = 0; i < n; i++)
            arr[i] /= 2;
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