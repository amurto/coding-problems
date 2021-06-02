// https://www.hackerrank.com/contests/w16/challenges/vim-war
// Vim War

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

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
    int n, m, req = 0, res = 0;
    cin >> n >> m;
    string tmp;
    vector<int> arr(n), f(1 << m);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int b = 0; b < m; b++)
            if (tmp[b] == '1')
                arr[i] |= (1 << b);
        f[arr[i]]++;
    }
    cin >> tmp;
    for (int b = 0; b < m; b++)
        if (tmp[b] == '1')
            req |= (1 << b);
    for (int b = 0; b < m; b++)
        for (int mask = 0; mask < (1 << m); mask++)
            if ((mask >> b) & 1)
                f[mask] += f[mask ^ (1 << b)];
    for (int sub = req; sub >= 0; sub = (sub - 1) & req)
    {
        int b = __builtin_popcount(req ^ sub);
        if (b & 1)
            res = add(res, -add(power(2, f[sub], MOD), -1));
        else
            res = add(res, add(power(2, f[sub], MOD), -1));
        if (sub == 0)
            break;
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