// https://www.codechef.com/problems/CHSTR
// Chef and String

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 5e3 + 5;

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
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
    i--;
    // Fermat's Little Theorem
    // 1/(a! % mod) = a!^mod-2 % mod
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i--; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
}

// NCR
// n!/r!*(n-r)!
int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return mul(fact[n], mul(invfact[r], invfact[n - r]));
}

vector<int> z_function(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve()
{
    int n, q;
    string str;
    cin >> n >> q >> str;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        string tmp = str.substr(n - i, i);
        vector<int> z = z_function(tmp);
        z[0] = i;
        vector<int> diff(i + 2);
        for (int j = 0; j < i; j++)
        {
            if (z[j] > 0)
            {
                diff[1]++;
                diff[z[j] + 1]--;
            }
        }
        for (int j = 1; j <= i; j++)
            diff[j] += diff[j - 1];
        for (int j = 1; j <= i; j++)
        {
            if (diff[j] > 0)
            {
                cnt[diff[j] - 1]--;
                cnt[diff[j]]++;
            }
        }
    }
    vector<int> choices(n + 2);
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= i; k++)
            choices[k] = add(choices[k], mul(cnt[i], ncr(i, k)));
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        k = min(k, n + 1);
        cout << choices[k] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}