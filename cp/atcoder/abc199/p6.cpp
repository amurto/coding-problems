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

Matrix mat_exp(Matrix a, int p)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, u, v;
    cin >> n >> m >> k;
    vector<int> arr(n), d(n);
    vector<vector<int>> g(n, vector<int>(n)), col(n, vector<int>(1));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        col[i][0] = arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        d[u]++;
        d[v]++;
        g[u][v] = g[v][u] = 1;
    }
    int den = power(mul(2, m), MOD - 2, MOD);
    for (int i = 0; i < n; i++)
        g[i][i] = mul(add(mul(2, m), -d[i]), den);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && g[i][j] == 1)
                g[i][j] = den;
    Matrix res = mat_exp(Matrix(g), k) * Matrix(col);
    for (int i = 0; i < n; i++)
        cout << res.mat[i][0] << "\n";
    return 0;
}