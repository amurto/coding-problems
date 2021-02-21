#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

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
    int a, b, c;
    cin >> a >> b >> c;
    int d = power(b, c, 4);
    if (d == 0)
        d += 4;
    int one = a % 10;
    return power(one, d, 1e9) % 10;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}