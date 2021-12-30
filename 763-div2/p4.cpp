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

int calc_mask(int di, int dj)
{
    if (di == 1 && dj == 1)
        return 0;
    else if (di == 1 && dj == -1)
        return 1;
    else if (di == -1 && dj == 1)
        return 2;
    return 3;
}

int solve()
{
    int n, m, rb, cb, rd, cd, p, res = 0;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    int q = 100 - p;
    p = mul(p, inv(100));
    q = mul(q, inv(100));
    vector<vector<vector<int>>> vis(n + 1, vector<vector<int>>(m + 1, vector<int>(4))), tour(n + 1, vector<vector<int>>(m + 1, vector<int>(4)));
    vector<int> pre;
    int mx = n * m * 5;
    for (int i = rb, j = cb, di = 1, dj = 1, dis = 0; dis < mx; dis++)
    {
        pre.pb(0);
        if (dis > 0)
            pre[dis] = pre[dis - 1];
        int mask = calc_mask(di, dj);
        if (i == rd || j == cd)
        {
            pre[dis]++;
            if (vis[i][j][mask] == 1)
            {
                int r = pre[dis] - pre[tour[i][j][mask]], dis_diff = dis - tour[i][j][mask], a = pre[dis] - 1;
                int qr = power(q, r, MOD), qa = power(q, a, MOD);
                int qr_inv = inv(add(1, -qr));
                res = add(res, mul(tour[i][j][mask], mul(qr_inv, power(q, pre[tour[i][j][mask]] - 1, MOD))));
                qr_inv = mul(qr_inv, qr_inv);
                res = add(res, mul(dis_diff, mul(qr_inv, qa)));
            }
        }
        tour[i][j][mask] = dis;
        vis[i][j][mask]++;
        if (i == n && di == 1)
            di = -1;
        else if (i == 1 && di == -1)
            di = 1;
        if (j == m && dj == 1)
            dj = -1;
        else if (j == 1 && dj == -1)
            dj = 1;
        i += di;
        j += dj;
    }
    res = mul(res, p);
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