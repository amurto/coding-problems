#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 200;
int dp[N][N];

// Mahonan Numbers
int inv(int n, int k)
{
    if (k == 0)
        return dp[n][k] = 1;
    if (n == 0)
        return dp[n][k] = 0;
    if (dp[n][k] == -1)
    {
        int j = 0, res = 0;
        for (j = 0; j < n && k - j >= 0; j++)
            res += inv(n - 1, k - j);
        dp[n][k] = res;
    }
    return dp[n][k];
}

void solve()
{
    int n;
    cin >> n;
    ll num = 0, den = 1;
    for (int i = n; i > 0; i--)
        den *= 1ll * i;
    memset(dp, -1, sizeof(dp));
    int mx = n * (n - 1) / 2;
    for (int i = 0; i <= mx; i++)
        num += i * 1ll * inv(n, i);
    ll g = __gcd(num, den);
    num /= g;
    den /= g;
    cout << num << " " << den << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}