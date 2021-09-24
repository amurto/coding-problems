// https://codeforces.com/contest/1155/problem/E
// Guess the Root

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

const int MOD = 1e6 + 3, K = 49;

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
int power(int n, int m, int p = MOD)
{
    int res = 1 % p;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

int Gauss(vector<vector<int>> a, vector<int> &ans)
{
    int n = a.size(), m = (int)a[0].size() - 1, free_var = 0, det = 1, rank = 0;
    vector<int> pos(m, -1);
    for (int col = 0, row = 0; col < m && row < n; col++)
    {
        int mx = row;
        for (int k = row; k < n; k++)
            if (a[k][col] > a[mx][col])
                mx = k;
        if (a[mx][col] == 0)
        {
            det = 0;
            continue;
        }
        for (int j = col; j <= m; j++)
            swap(a[mx][j], a[row][j]);
        if (row != mx)
            det = det == 0 ? 0 : MOD - det;
        det = mul(det, a[row][col]);
        pos[col] = row;
        int inv = power(a[row][col], MOD - 2);
        for (int i = 0; i < n && inv; i++)
        {
            if (i != row && a[i][col])
            {
                int x = mul(a[i][col], inv);
                for (int j = col; j <= m && x; j++)
                    if (a[row][j])
                        a[i][j] = add(a[i][j], -mul(a[row][j], x));
            }
        }
        row++;
        ++rank;
    }
    ans.assign(m, 0);
    for (int i = 0; i < m; i++)
        if (pos[i] == -1)
            free_var++;
        else
            ans[i] = mul(a[pos[i]][m], power(a[pos[i]][i], MOD - 2));
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        for (int j = 0; j < m; j++)
            val = add(val, mul(ans[j], a[i][j]));
        if (val != a[i][m])
            return -1; //no solution
    }
    return free_var; //has solution
}

int query(int x)
{
    cout << "? " << x << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

int offline_query(vector<int> &ans, int p, int x)
{
    int val = p, y = x;
    for (int i = 0; i < (int)ans.size(); i++, y = mul(y, x))
        val = add(val, mul(y, ans[i]));
    return val;
}

int solve()
{
    int p = query(0);
    vector<vector<int>> g(K, vector<int>(11));
    for (int i = 1; i <= K; i++)
    {
        g[i - 1][10] = add(query(i), -p);
        g[i - 1][0] = i;
        for (int j = 1; j < 10; j++)
            g[i - 1][j] = mul(g[i - 1][j - 1], i);
    }
    vector<int> ans;
    if (Gauss(g, ans) == -1)
        return -1;
    for (int i = 0; i < MOD; i++)
        if (offline_query(ans, p, i) == 0)
            return i;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int res = solve();
    cout << "! " << res << endl;
    return 0;
}