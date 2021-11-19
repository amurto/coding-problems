// https://codeforces.com/contest/718/problem/C
// Sasha and Array

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

struct Matrix
{
    int mat[2][2] = {{0, 0}, {0, 0}};
    Matrix() {}
    Matrix(int a, int b, int c, int d)
    {
        mat[0][0] = a;
        mat[0][1] = b;
        mat[1][0] = c;
        mat[1][1] = d;
    }

    static Matrix identity_matrix(int n)
    {
        return Matrix(1, 0, 0, 1);
    }

    Matrix operator*(const Matrix &other) const
    {
        int result[2][2];
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                int tmp = 0;
                for (int k = 0; k < 2; k++)
                    tmp = add(tmp, mul(mat[i][k], other.mat[k][j]));
                result[i][j] = tmp;
            }
        return Matrix(result[0][0], result[0][1], result[1][0], result[1][1]);
    }
};

Matrix mat_exp(Matrix a, ll p)
{
    Matrix result = Matrix::identity_matrix(2);
    while (p > 0)
    {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}

Matrix TT = Matrix(0, 1, 1, 1), col = Matrix(0, 0, 1, 0);
struct node
{
    Matrix M = Matrix(0, 0, 0, 0); // identity
    node() {}
    void merge(const node &l, const node &r)
    {
        M.mat[0][0] = add(l.M.mat[0][0], r.M.mat[0][0]);
        M.mat[1][0] = add(l.M.mat[1][0], r.M.mat[1][0]);
    }
};

struct update
{
    ll v = 0;
    Matrix M = Matrix(1, 0, 0, 1);
    update() {}
    update(ll val)
    {
        v = val;
        M = mat_exp(TT, val);
    }
    // combine the current update with the other update
    void combine(update &other, const int32_t &tl, const int32_t &tr)
    {
        M = M * other.M;
        v += other.v;
    }
    // store the correct information in the node x
    // apply x.v+=(tr-tl+1)*v for range addition and query sum
    void apply(node &x, const int32_t &tl, const int32_t &tr)
    {
        x.M = M * x.M;
    }
};

template <typename node, typename update>
struct segtree
{
    int len;
    vector<node> t;
    vector<update> u;
    vector<bool> lazy;
    node identity_element;
    update identity_transformation;
    segtree(int l)
    {
        len = l;
        t.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        identity_element = node();
        identity_transformation = update();
    }
    segtree() = default;
    void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (!lazy[v])
            return;
        int32_t tm = (tl + tr) >> 1;
        apply(v << 1, tl, tm, u[v]);
        apply(v << 1 | 1, tm + 1, tr, u[v]);
        u[v] = identity_transformation;
        lazy[v] = 0;
    }

    void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd)
    {
        if (tl != tr)
        {
            lazy[v] = 1;
            u[v].combine(upd, tl, tr);
        }
        upd.apply(t[v], tl, tr);
    }

    template <typename T>
    void build(const T &arr, const int32_t &v, const int32_t &tl, const int32_t &tr)
    {
        if (tl == tr)
        {
            t[v].M = mat_exp(TT, arr[tl]) * col;
            return;
        }
        int32_t tm = (tl + tr) >> 1;
        build(arr, v << 1, tl, tm);
        build(arr, v << 1 | 1, tm + 1, tr);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

    node query(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r)
    {
        if (l > tr || r < tl)
            return identity_element;
        if (l <= tl && tr <= r)
            return t[v];
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        node a = query(v << 1, tl, tm, l, r), b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }

    // rupd = range update
    void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr, const int32_t &l, const int32_t &r, const update &upd)
    {
        if (l > tr || r < tl)
            return;
        if (l <= tl && tr <= r)
        {
            apply(v, tl, tr, upd);
            return;
        }
        pushdown(v, tl, tr);
        int32_t tm = (tl + tr) >> 1;
        rupd(v << 1, tl, tm, l, r, upd);
        rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
        t[v].merge(t[v << 1], t[v << 1 | 1]);
    }

public:
    template <typename T>
    void build(const T &arr)
    {
        build(arr, 1, 0, len - 1);
    }
    node query(const int32_t &l, const int32_t &r)
    {
        return query(1, 0, len - 1, l, r);
    }
    void rupd(const int32_t &l, const int32_t &r, const update &upd)
    {
        rupd(1, 0, len - 1, l, r, upd);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    segtree<node, update> s(n);
    s.build(arr);
    for (int i = 0; i < m; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        if (t == 1)
        {
            ll x;
            cin >> x;
            s.rupd(l, r, x);
        }
        else
            cout << s.query(l, r).M.mat[0][0] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}