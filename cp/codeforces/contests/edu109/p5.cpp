#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;

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

int solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    int fac = 1;
    for (int i = 1; i <= n; i++)
        fac = mul(fac, i);
    vector<vector<int>> dis(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> dis[i][j];
    for (int j = 0; j < m; j++)
    {
        vector<int> seq(n + 2);
        for (int i = 0; i < n; i++)
            seq[n - dis[i][j] + 2]++;
        int p = 1, cur = 0;
        for (int i = 1; i <= n; i++)
        {
            cur += seq[i];
            p = mul(p, cur);
            cur--;
        }
        res = add(res, add(fac, -p));
    }
    res = mul(res, power(fac, MOD - 2, MOD));
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