// https://codeforces.com/contest/222/problem/E
// Decoding Genome

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

map<char, int> mp;
void init()
{
    for (char ch = 'a', i = 0; ch <= 'z'; ch++, i++)
        mp[ch] = i;
    for (char ch = 'A', i = 26; ch <= 'Z'; ch++, i++)
        mp[ch] = i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    ll n;
    int m, k, res = 0;
    cin >> n >> m >> k;
    vector<vector<int>> arr(m, vector<int>(m, 1)), col(m, vector<int>(1, 1));
    string str;
    for (int i = 0; i < k; i++)
    {
        cin >> str;
        arr[mp[str[1]]][mp[str[0]]] = 0;
    }
    Matrix M = mat_exp(Matrix(arr), n - 1) * Matrix(col);
    for (int i = 0; i < m; i++)
        res = add(res, M.mat[i][0]);
    cout << res << "\n";
    return 0;
}