// https://codeforces.com/contest/1312/problem/E
// Array Shrinking

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

const int inf = 1e9 + 7;
int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> cdp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
        cdp[i][i] = arr[i];
    for (int gap = 1; gap < n; gap++)
        for (int i = 0, j = gap; j < n; i++, j++)
            for (int k = i; k < j; k++)
                if (cdp[i][k] != -1 && cdp[i][k] == cdp[k + 1][j])
                    cdp[i][j] = cdp[i][k] + 1;
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] = min(dp[i], dp[j] + ((cdp[j][i - 1] == -1) ? inf : 1));
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}