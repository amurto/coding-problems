#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q;
    cin >> n;
    vector<int> arr(n + 1), par(n + 1), st(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    dp[0][0] = n;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][par[arr[i]]]--;
        par[arr[i]] ^= 1;
        dp[i][par[arr[i]]]++;
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        int diff = (abs(dp[r][0] - dp[l - 1][0]) + abs(dp[r][1] - dp[l - 1][1])) / 2;
        int res = (r - l + 1 - diff) / 2;
        cout << res << "\n";
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