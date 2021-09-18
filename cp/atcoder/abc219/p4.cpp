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

const int N = 305, inf = 1000;
int dp[N][N][N], A[N], B[N];
int dfs(int cur, int rem_x, int rem_y, int n)
{
    if (rem_x + rem_y == 0)
        return 0;
    if (cur == n)
        return inf;
    if (dp[cur][rem_x][rem_y] == -1)
        dp[cur][rem_x][rem_y] = min(1 + dfs(cur + 1, max(0, rem_x - A[cur]), max(0, rem_y - B[cur]), n), dfs(cur + 1, rem_x, rem_y, n));
    return dp[cur][rem_x][rem_y];
}

int solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i];
    memset(dp, -1, sizeof(dp));
    int ans = dfs(0, x, y, n);
    return ans >= inf ? -1 : ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}