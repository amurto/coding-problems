// https://codeforces.com/contest/1458/problem/B
// Glass Half Spilled

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e4 + 5, ninf = -1e7;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> dp(N, vector<int>(n + 1, ninf));
    vector<double> res(n + 1);
    double w = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        w += 1.0 * b[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = N - 1; j >= a[i]; j--)
            for (int k = 1; k <= n; k++)
                dp[j][k] = max(dp[j][k], b[i] + dp[j - a[i]][k - 1]);
    for (int k = 1; k <= n; k++)
        for (int j = 0; j < N; j++)
            res[k] = max(res[k], min(1.0 * j, (1.0 * dp[j][k] + w) / 2.0));
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    solve();
    return 0;
}