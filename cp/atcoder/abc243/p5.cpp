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

const ll inf = 1e18;
int solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> A(m), B(m);
    vector<ll> C(m);
    vector<vector<ll>> dp(n, vector<ll>(n, inf));
    // set distance to itself as 0
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
        // for bidirectional
        dp[A[i] - 1][B[i] - 1] = C[i];
        dp[B[i] - 1][A[i] - 1] = C[i];
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    for (int i = 0; i < m; i++)
    {
        int u = A[i] - 1, v = B[i] - 1, pos = 0;
        for (int j = 0; pos == 0 && j < n; j++)
            if (j != u && j != v && dp[u][j] + dp[j][v] <= C[i])
                pos = 1;
        res += pos;
    }
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