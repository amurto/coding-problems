#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int bcs(vector<vector<int>> &dp, int cur, int x, int odd, int even, int player)
{
    if (cur == x)
        if (odd & 1)
            return 0;
        else
            return 1;
    if (dp[odd][even] == -1)
    {
        int c1 = -1, c2 = -1, next = player ^ 1;
        if (odd > 0)
            c1 = bcs(dp, cur + 1, x, odd - 1, even, next);
        if (even > 0)
            c2 = bcs(dp, cur + 1, x, odd, even - 1, next);
        if (c1 == player || c2 == player)
            dp[odd][even] = player;
        else
            dp[odd][even] = next;
    }
    return dp[odd][even];
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
        int n, x, odd = 0, even = 0;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] & 1)
                odd++;
            else
                even++;
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = bcs(dp, 0, x, odd, even, 0);
        if (ans & 1)
            cout << "Jesse\n";
        else
            cout << "Walter\n";
    }
    return 0;
}