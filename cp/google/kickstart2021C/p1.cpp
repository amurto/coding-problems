#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 1e5 + 5;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int dp[N][2];
int dfs(string &str, int cur, int f, int n, int k, int fin)
{
    if (cur == n / 2)
    {
        if (f == 1)
            return fin;
        else
        {
            if (n & 1)
                return k;
            return 1;
        }
    }
    if (dp[cur][f] == -1)
    {
        int lim = k - 1, res = 0;
        if (f == 1)
            lim = str[cur] - 'a';
        for (int a = 0; a <= lim; a++)
        {
            if (a == lim)
                res = add(res, dfs(str, cur + 1, f, n, k, fin));
            else
                res = add(res, dfs(str, cur + 1, 0, n, k, fin));
        }
        dp[cur][f] = res;
    }
    return dp[cur][f];
}

int solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    memset(dp, -1, sizeof(dp));
    string pal = str;
    for (int i = 0, j = n - 1; i < n / 2; i++, j--)
        pal[j] = str[i];
    int fin = (pal.compare(str) < 0);
    if (n & 1)
        fin += str[n / 2] - 'a';
    return dfs(str, 0, 1, n, k, fin);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}