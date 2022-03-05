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

const int MOD = 998244353, N = 1e6 + 5;

int pw26[N];
int add(int x, int y)
{
    x += y;
    x %= MOD;
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

int solve()
{
    int n, res = 0;
    string str;
    cin >> n >> str;
    int h = n / 2;
    for (int i = 0; i < h; i++)
    {
        if (str[i] > 'A')
        {
            if (n & 1)
                res = add(res, mul(str[i] - 'A', pw26[h - i]));
            else
                res = add(res, mul(str[i] - 'A', pw26[h - 1 - i]));
        }
    }
    string tmp(n, '0');
    for (int i = 0, j = n - 1; i < h; i++, j--)
        tmp[i] = tmp[j] = str[i];
    if (n & 1)
    {
        for (char ch = 'A'; ch <= 'Z'; ch++)
        {
            tmp[h] = ch;
            if (tmp <= str)
                res = add(res, 1);
        }
    }
    else
    {
        if (tmp <= str)
            res = add(res, 1);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pw26[0] = 1;
    for (int i = 1; i < N; i++)
        pw26[i] = mul(pw26[i - 1], 26);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}