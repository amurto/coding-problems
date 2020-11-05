// RUN

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1000000007, N = 100001;

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
// p is large prime number
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
int two[N], fact[N], invfact[N];
void init()
{
    two[0] = 1;
    for (int i = 1; i < N; i++)
        two[i] = (two[i - 1] * 1ll * 2) % MOD;
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

// NCR
// n!/r!*(n-r)!
int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return mul(fact[n], mul(invfact[r], invfact[n - r]));
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
    {
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
            arr[i].second = i;
        }

        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        for (int i = 0; i < n; i++)
        {
            // number of subsets from array of length n is 2^n
            // rem = 2^(n-i-1) - 1
            // ans = ncr(i, 2) + ncr(i, 2) * rem + i + i * rem + rem;
            int rem = two[n - i - 1] - 1;
            int ans = add(ncr(i, 2), mul(ncr(i, 2), rem));
            ans = add(ans, i);
            ans = add(ans, mul(i, rem));
            ans = add(ans, rem);
            res[arr[i].second] = ans;
        }
        for (int val: res)
            cout << val << " ";
        cout << "\n";
    }
    return 0;
}