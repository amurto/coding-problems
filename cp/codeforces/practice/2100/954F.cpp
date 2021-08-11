// https://codeforces.com/contest/954/problem/F
// Runner's Problem

#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back

const int MOD = 1e9 + 7;
class segment
{
public:
    int a;
    ll l, r;
    segment() {}
    segment(int a, ll l, ll r) : a(a), l(l), r(r) {}
    bool operator<(const segment &other) const
    {
        if (l == other.l)
            return (r < other.r);
        return (l <= other.l);
    }
};

vector<vector<int>> id = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};

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
        p >>= 1ll;
    }
    return result;
}

int solve()
{
    int n, a, sum = 0;
    ll m, l, r;
    cin >> n >> m;
    vector<segment> arr;
    vector<pii> segs;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> l >> r;
        a--;
        arr.pb(segment(a, l, r));
    }
    sort(arr.begin(), arr.end());
    if (arr[0].l > 2)
        segs.pb({2, 0});
    vector<int> obs(3);
    ll cur = arr[0].l;
    int i = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    while (cur < m)
    {
        while (!pq.empty() && pq.top().first == cur)
        {
            obs[pq.top().second]--;
            pq.pop();
        }
        while (i < n && arr[i].l == cur)
        {
            obs[arr[i].a]++;
            pq.push({arr[i].r + 1, arr[i].a});
            i++;
        }
        int st = 0;
        for (int j = 0; j < 3; j++)
            if (obs[j] > 0)
                st |= (1 << j);
        segs.pb({cur, st});
        ll nxt = m;
        if (i < n)
            nxt = min(nxt, arr[i].l);
        if (!pq.empty())
            nxt = min(nxt, pq.top().first);
        cur = nxt;
    }
    vector<vector<int>> dp(3, vector<int>(1));
    dp[1][0] = 1;
    for (int i = 0; i < segs.size(); i++)
    {
        vector<vector<int>> tdp(3, vector<int>(1));
        ll nxt = m;
        if (i + 1 < segs.size())
            nxt = segs[i + 1].first;
        ll len = nxt - segs[i].first;
        int b = segs[i].second;
        for (int j = 0; j < 3; j++)
            if (((b >> j) & 1) == 0)
                for (int c = -1; c <= 1; c++)
                    if (j + c >= 0 && j + c < 3)
                        tdp[j][0] = add(tdp[j][0], dp[j + c][0]);
        vector<vector<int>> tmp = id;
        for (int j = 0; j < 3; j++)
            if ((b >> j) & 1)
                for (int idx = 0; idx < 3; idx++)
                    tmp[idx][j] = tmp[j][idx] = 0;
        Matrix res = mat_exp(Matrix(tmp), len - 1) * Matrix(tdp);
        for (int j = 0; j < 3; j++)
            tdp[j][0] = res.mat[j][0];
        dp = tdp;
    }
    for (int j = 0; j < 3; j++)
        sum = add(sum, dp[j][0]);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}