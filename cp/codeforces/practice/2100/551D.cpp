// https://codeforces.com/contest/551/problem/D
// GukiZ and Binary Operations

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

int MOD;
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
int power(int n, ll m, int p)
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

struct Matrix
{
    vector<vector<int>> mat;
    int n_rows, n_cols;

    Matrix() {}

    Matrix(vector<vector<int>> values) : mat(values), n_rows(values.size()),
                                         n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n)
    {
        vector<vector<int>> values(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        int n = n_rows, m = other.n_cols;
        vector<vector<int>> result(n_rows, vector<int>(n_cols, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int tmp = 0;
                for (int k = 0; k < n_cols; k++)
                    tmp = add(tmp, mul(mat[i][k], other.mat[k][j]));
                result[i][j] = tmp;
            }
        return move(Matrix(move(result)));
    }

    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
};

Matrix mat_exp(Matrix a, ll p)
{
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0)
    {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}

int solve()
{
    ll n, k, l;
    cin >> n >> k >> l >> MOD;
    if (MOD == 1)
        return 0;
    if (l <= 60 && ((1ll << l) - 1) < k)
        return 0;
    vector<vector<int>> identity = {{1, 1}, {1, 0}}, col = {{1}, {0}};
    int p = power(2, n, MOD), res = 1;
    Matrix mt = mat_exp(Matrix(identity), n) * Matrix(col);
    vector<int> dp(2);
    dp[0] = add(mt.mat[0][0], mt.mat[1][0]);
    dp[1] = add(p, -dp[0]);
    for (int i = 0; i < l; i++)
        res = mul(res, dp[(k >> i) & 1]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}