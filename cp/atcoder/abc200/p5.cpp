#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 3000105;
ll dp[3][N];

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[1][i + 1] += dp[0][i];
        dp[1][i + n + 1] -= dp[0][i];
    }
    for (int i = 1; i <= 2 * n + 5; i++)
        dp[1][i] += dp[1][i - 1];
    for (int i = 2; i <= 2 * n; i++)
    {
        dp[2][i + 1] += dp[1][i];
        dp[2][i + n + 1] -= dp[1][i];
    }
    for (int i = 1; i <= 3 * n + 5; i++)
        dp[2][i] += dp[2][i - 1];
    ll pre = 0, last = 0;
    int sum = 3 * n + 1;
    for (int i = 3; i <= 3 * n; i++)
    {
        pre += dp[2][i];
        if (pre >= k)
        {
            sum = i;
            k -= last;
            break;
        }
        last = pre;
    }
    vector<int> tmp;
    pre = 0;
    last = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i < sum)
            pre += dp[1][sum - i];
        if (pre >= k)
        {
            tmp.pb(i);
            k -= last;
            break;
        }
        last = pre;
    }
    sum -= tmp.back();
    pre = 0;
    last = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i < sum)
            pre += dp[0][sum - i];
        if (pre >= k)
        {
            tmp.pb(i);
            k -= last;
            break;
        }
        last = pre;
    }
    sum -= tmp.back();
    tmp.pb(sum);
    for (int i = 0; i < 3; i++)
        cout << tmp[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}