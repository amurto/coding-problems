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

int solve()
{
    int n;
    cin >> n;
    int res = add(power(2, n, MOD), -1);
    vector<int> arr(n + 1), cnt(30);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        int b = 0;
        while (arr[i] % 2 == 0)
        {
            arr[i] /= 2;
            b++;
        }
        if (b > 0)
            cnt[b]++;
    }
    int pre = 0;
    for (int b = 29; b > 0; b--)
    {
        if (cnt[b] > 0)
            res = add(res, -mul(power(2, pre, MOD), power(2, cnt[b] - 1, MOD)));
        pre += cnt[b];
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