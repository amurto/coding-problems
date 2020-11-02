#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1000000007, N = 2000;

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

int fact[N], invfact[N];
void init()
{
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
    i--;
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i--; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
}

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
    int n, x, pos;
    cin >> n >> x >> pos;

    int left = 0, right = n, low = 0, high = 0;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mid < pos)
            low++;
        if (mid > pos)
            high++;
        if (mid <= pos)
            left = mid + 1;
        else
            right = mid;
    }
    vector<int> muls = {fact[n - low - high - 1], ncr(x - 1, low), ncr(n - x, high), fact[low], fact[high]}; 
    int ans=1;
    for (int m: muls)
        ans = mul(ans, m);
    cout << ans << "\n";
    return 0;
}

