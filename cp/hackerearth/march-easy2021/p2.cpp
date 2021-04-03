#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int add(int x, int y, int MOD)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y, int MOD)
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
    int n, k;
    string str;
    cin >> n >> k >> str;
    vector<int> pre(n + 1), suf(n + 1), d(n + 1);
    for (int i = n - 1; i >= 0; i--)
        suf[i] = add(mul(str[i] - '0', power(10, n - i - 1, k), k), suf[i + 1], k);
    pre[0] = str[0] - '0';
    for (int i = 1; i < n; i++)
        pre[i] = add(mul(pre[i - 1], 10, k), str[i] - '0', k);
    int res = max(suf[0], suf[1]);
    for (int i = 1; i < n; i++)
        res = max(res, add(mul(pre[i - 1], power(10, n - i - 1, k), k), suf[i + 1], k));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}