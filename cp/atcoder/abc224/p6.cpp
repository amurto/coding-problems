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

const int MOD = 998244353, N = 2e5 + 5;

int pw2[N];
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

int p2(int v)
{
    return (v < 0) ? 1 : pw2[v];
}

int solve()
{
    string str;
    cin >> str;
    int n = str.length(), res = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = str[i] - '0';
    for (int i = 0, pre = 0; i < n; i++)
    {
        pre = add(mul(pre, 10), mul(p2(i), arr[i]));
        res = add(res, mul(pre, p2(n - i - 2)));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pw2[0] = 1;
    for (int i = 1; i < N; i++)
        pw2[i] = mul(pw2[i - 1], 2);
    cout << solve() << "\n";
    return 0;
}