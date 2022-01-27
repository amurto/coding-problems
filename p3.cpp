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

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), dp(n), last(n + 1, -1), tp(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (i - 1 >= 0)
            dp[i] = dp[i - 1];
        int val = arr[i];
        if (last[val] >= 0)
        {
            tp[i] = i - last[val] + tp[last[val]];
            dp[i] = max(dp[i], max(dp[last[val]], tp[last[val]]) + i - last[val] - 1);
            tp[i] = max(tp[i], dp[i] + 1);
        }
        last[val] = i;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dp[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}