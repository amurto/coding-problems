#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
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

int inv(int x)
{
    return power(x, MOD - 2, MOD);
}
int solve()
{
    int B, W;
    cin >> B >> W;
    int b1 = mul(B, inv(B + W)), w1 = mul(W, inv(B + W));
    int odd1 = mul(b1, inv(add(1, -mul(w1, w1))));
    int even1 = mul(odd1, w1);
    B--;
    int b2 = mul(B, inv(B + W)), w2 = mul(W, inv(B + W));
    int odd2 = mul(b2, inv(add(1, -mul(w2, w2))));
    int even2 = mul(odd2, w2);
    return add(mul(odd1, even2), mul(even1, odd2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}