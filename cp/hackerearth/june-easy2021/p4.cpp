#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e14;
const int N = 2005;
ll dp[N][N], P[N], V[N];

ll dfs(int cur, ll sum, int n)
{
    if (sum >= n)
        return 0ll;
    if (cur == n)
        return inf;
    if (dp[cur][sum] == -1)
        dp[cur][sum] = min(dfs(cur + 1, sum, n), P[cur] + dfs(cur + 1, sum + V[cur], n));
    return dp[cur][sum];
}

ll solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> V[i] >> P[i];
        V[i]++;
    }
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, n);
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