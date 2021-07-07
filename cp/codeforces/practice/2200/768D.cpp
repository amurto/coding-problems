// https://codeforces.com/contest/768/problem/D
// Jon and Orbs

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const double eps = 1e-7;

void solve()
{
    int k, q, x;
    cin >> k >> q;
    int cur = 1;
    vector<int> res(1001);
    vector<double> dp(k + 1);
    dp[0] = 1.0;
    for (int i = 1; cur <= 1000; i++)
    {
        for (int j = k; j > 0; j--)
            dp[j] = (1.0 * j * dp[j] + 1.0 * (k - j + 1) * dp[j - 1]) / k;
        dp[0] = 0.0;
        while (cur <= 1000 && 2000 * dp[k] >= (cur - eps))
        {
            res[cur] = i;
            cur++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        cout << res[x] << "\n";
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