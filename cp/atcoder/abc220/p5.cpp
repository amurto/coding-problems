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

const int MOD = 998244353, N = 1e7 + 5;
int two[N];

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

void init()
{
    two[0] = 1;
    for (int i = 1; i < N; i++)
        two[i] = mul(two[i - 1], 2);
}

int pw2(int x)
{
    if (x == -1)
        return 1;
    if (x < 0)
        return 0;
    return two[x];
}

int solve()
{
    int n, d, cnt = 0, res = 0;
    cin >> n >> d;
    int h = d / 2;
    for (int i = 1; i < n; i++)
    {
        if (d <= 2 * i)
            cnt = add(cnt, pw2(d - i - 1));
        res = add(res, mul(two[i], cnt));
        if (d % 2 == 0)
            if (i >= h)
                res = add(res, -mul(two[i - 1], pw2(h - 1)));
    }
    return mul(2, res);
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