#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;
int dp[1 << 6][1 << 6], fib[7], st[1 << 6];

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

void init(int h)
{

    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i <= 6; i++)
        fib[i] = add(fib[i - 2], fib[i - 1]);
    memset(dp, 0, sizeof(dp));
    memset(st, 0, sizeof(st));
    for (int i = 0; i < (1 << h); i++)
    {
        int cur = i, last = 0;
        vector<int> tmp;
        while (cur > 0)
        {
            tmp.pb(cur % 2);
            cur /= 2;
        }
        st[i] = 1;
        for (int e : tmp)
        {
            if (e == 1)
                last++;
            else
            {
                st[i] = mul(st[i], fib[last]);
                last = 0;
            }
        }
        st[i] = mul(st[i], fib[last]);
    }
    int mx = (1 << h) - 1;
    for (int mask = 0; mask < (1 << h); mask++)
    {
        for (int j = mask; j >= 0; j = (j - 1) & mask)
        {
            dp[mask][j | (mask ^ mx)] = st[j];
            if (j == 0)
                break;
        }
    }
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
    int h;
    ll w;
    cin >> h >> w;
    init(h);
    int sz = 1 << h;
    vector<vector<int>> T(sz, vector<int>(sz)), arr(sz, vector<int>(1));
    for (int i = 0; i < sz; i++)
        arr[i][0] = st[i];
    for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz; j++)
            T[i][j] = dp[j][i];
    Matrix res = mat_exp(Matrix(T), w - 1) * Matrix(arr);
    return res.mat[sz - 1][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}