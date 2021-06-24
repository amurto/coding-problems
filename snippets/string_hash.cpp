#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y, int m = MOD)
{
    x += y;
    while (x >= m)
        x -= m;
    while (x < 0)
        x += m;
    return x;
}

int mul(int x, int y, int m = MOD)
{
    return (x * 1ll * y) % m;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p = MOD)
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

class polyhash
{
public:
    // m is big prime
    // p is prime greater than size of alphabet
    // h is hash(str)
    string str;
    int n, m, p, h;
    vector<int> pre, inv;
    polyhash() {}
    polyhash(string str, int m, int p) : str(str), m(m), p(p)
    {
        n = str.length();
        pre.resize(n);
        inv.resize(n);
        precompute();
    }

    void precompute()
    {
        int last = 0, pw = 1;
        for (int i = 0; i < n; i++)
        {
            pre[i] = add(last, mul(pw, str[i] - 'a' + 1));
            last = pre[i];
            pw = mul(pw, p, m);
        }
        int v = power(pw, m - 2, m);
        for (int i = n - 1; i >= 0; i--)
        {
            inv[i] = mul(v, p);
            v = inv[i];
        }
        h = pre.back();
    }

    // get hash of substring [l,...,r]
    int query(int l, int r)
    {
        int cur = pre[r];
        if (l > 0)
            cur = add(cur, -pre[l - 1]);
        cur = mul(cur, inv[l]);
        return cur;
    }
};

int solve()
{
    string str;
    cin >> str;
    polyhash ph = polyhash(str, MOD, 31);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}