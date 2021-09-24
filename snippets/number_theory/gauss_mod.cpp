// Stolen from https://github.com/ShahjalalShohag/code-library/blob/master/Math/Gaussian%20Elimination.cpp
// Tested with https://codeforces.com/contest/1155/problem/E

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // number of unknown variables -> m
    // more equations are better
    // 4x + 3y + 2z = 16
    // 2x + 3y + 4z = 20
    // x + y + z = 6
    // x + 2y + z = 8
    // x = 1, y = 2, z = 3
    vector<vector<int>> a = {{4, 3, 2, 16}, {2, 3, 4, 20}, {1, 1, 1, 6}, {1, 2, 1, 8}};
    vector<int> ans;
    int v = Gauss(a, ans);
    return 0;
}