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

const int MOD = 998244353;

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
    int n, m, k, q, res = 1;
    cin >> n >> m >> k >> q;
    vector<int> x(q), y(q);
    for (int i = 0; i < q; i++)
        cin >> x[i] >> y[i];
    set<int> rows, cols;
    for (int i = q - 1; (int)rows.size() < n && (int)cols.size() < m && i >= 0; i--)
    {
        if (rows.find(x[i]) == rows.end() || cols.find(y[i]) == cols.end())
            res = mul(res, k);
        rows.insert(x[i]);
        cols.insert(y[i]);
    }
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