// https://codeforces.com/contest/621/problem/E
// Wet Shark and Blocks

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
    int n, b, k, x, d;
    cin >> n >> b >> k >> x;
    vector<int> f(10);
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        f[d]++;
    }
    vector<vector<int>> T(x, vector<int>(x)), arr(x, vector<int>(1));
    arr[0][0] = 1;
    for (int i = 0; i < x; i++)
        for (int j = 1; j < 10; j++)
            T[(i * 10 + j) % x][i] += f[j];
    Matrix res = mat_exp(Matrix(T), b) * Matrix(arr);
    cout << res.mat[k][0] << "\n";
    return 0;
}