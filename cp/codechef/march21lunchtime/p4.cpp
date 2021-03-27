#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 1e3 + 5;
pair<int, int> dp[N][22];
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

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

bool same(string &b)
{
    for (int i = 1; i < b.length(); i++)
        if (b[i - 1] != b[i])
            return false;
    return true;
}

pair<int, int> codon(vector<vector<int>> &g, string &str, string &b, int n, int cur, int j)
{
    if (j == b.length())
        return {1, 1};
    if (dp[cur][j].second == -1)
    {
        bool f = false;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == cur || str[i - 1] != b[j] || g[cur][i] == 0)
                continue;
            pair<int, int> ret = codon(g, str, b, n, i, j + 1);
            if (ret.second)
            {
                f = true;
                res = add(res, mul(g[cur][i], ret.first));
            }
        }
        dp[cur][j].first = res;
        dp[cur][j].second = f;
    }
    return dp[cur][j];
}

int solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    string b, str;
    cin >> b >> str;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    vector<int> u(m), v(m);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < m; i++)
        cin >> u[i];
    for (int i = 0; i < m; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
    {
        g[u[i]][v[i]]++;
        g[v[i]][u[i]]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (str[i - 1] == b[0])
        {
            pair<int, int> ret = codon(g, str, b, n, i, 1);
            if (ret.second)
                res = add(res, ret.first);
        }
    }
    if (same(b))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (str[i - 1] != b[0] || str[j - 1] != b[0] || g[i][j] == 0)
                    continue;
                res = add(res, -power(g[i][j], l - 1, MOD));
            }
        }
    }
    return res;
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