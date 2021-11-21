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

const int MOD = 7, N = 1e4 + 5;
int ten[N];
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

void init()
{
    ten[0] = 1;
    for (int i = 1; i < N; i++)
        ten[i] = mul(ten[i - 1], 10);
}

int nc2(int x)
{
    return (x * (x + 1)) / 2;
}

string solve()
{
    int n;
    cin >> n;
    string res = "";
    char ch = '1';
    while (n > 0)
    {
        res.pb('0');
        vector<int> vis(7);
        for (int j = (int)res.length() - 1, m = 0, t = 0; j >= 0; j--, t++)
        {
            int c = res[j] - '0';
            m = add(m, mul(c, ten[t]));
            vis[m]++;
        }
        int mx = 0, cur = 0;
        for (int b = 1; b <= 9; b++)
        {
            int p = 0;
            for (int j = 0; j < 7; j++)
                if (add(j, b) == 0)
                    p += vis[j];
            if (p <= n && p >= mx)
            {
                mx = p;
                cur = b;
            }
        }
        res.back() += cur;
        n -= mx;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}