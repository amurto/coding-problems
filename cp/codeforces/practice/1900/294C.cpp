// https://codeforces.com/contest/294/problem/C
// Shaass and Lights

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1005, MOD = 1e9 + 7;

int two[N];
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

// factorial and inverse factorial
int fact[N], invfact[N];
void init()
{
    two[0] = 1;
    for (int i = 1; i < N; i++)
        two[i] = mul(two[i - 1], 2);
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
    i--;
    // Fermat's Little Theorem
    // 1/(a! % mod) = a^mod-2 % mod
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i--; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
}

int ways(int d)
{
    if (d == 0)
        return 1;
    return two[d - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int res = mul(fact[n - m], invfact[arr[0] - 1]);
    for (int i = 1; i < m; i++)
        res = mul(res, invfact[arr[i] - arr[i - 1] - 1]);
    if (arr[m - 1] < n)
        res = mul(res, invfact[n - arr[m - 1]]);
    for (int i = 0; i < m - 1; i++)
        res = mul(res, ways(arr[i + 1] - arr[i] - 1));
    cout << res << "\n";
    return 0;
}