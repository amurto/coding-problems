#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q-- > 0)
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1));
        for (int i = 1; i <= n; i++)
            for (int time = 0; time <= 2 * n; time++)
                if (i > time)
                    dp[i][time] = INT_MAX;
                else
                    dp[i][time] = min(abs(time - arr[i]) + dp[i - 1][time - 1], dp[i][time - 1]);

        cout << dp[n][2 * n] << "\n";
    }
    return 0;
}