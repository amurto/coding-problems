#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1000000007;

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

void factor(unordered_map<int, int> &PRIME, int num)
{
    unordered_map<int, int> F;
    for (int i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            num /= i;
            F[i]++;
        }
    }
    if (num > 1)
        F[num]++;
    for (auto f : F)
        PRIME[f.first] = max(PRIME[f.first], f.second);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // lcm = product of (prime factor ^ maximum times it divides any arr[i])
    unordered_map<int, int> PRIME;
    for (int num : arr)
        factor(PRIME, num);

    int lcm = 1;
    for (auto p : PRIME)
        lcm = mul(lcm, power(p.first, p.second, MOD));
    int res = 0;
    for (int num : arr)
        res = add(res, mul(lcm, power(num, MOD - 2, MOD)));
    cout << res << "\n";
    return 0;
}