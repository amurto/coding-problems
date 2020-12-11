// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944
// 10003 - Cutting Sticks

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int l;
    while (cin >> l && l)
    {
        int n;
        cin >> n;
        vector<int> arr(n + 2);
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        arr[n + 1] = l;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, INT_MAX));
        for (int i = 0; i < n + 1; i++)
            dp[i][i + 1] = 0;
        for (int gap = 2; gap < n + 2; gap++)
            for (int i = 0, j = gap; j < n + 2; i++, j++)
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], abs(arr[j] - arr[i]) + dp[i][k] + dp[k][j]);
        cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }
    return 0;
}