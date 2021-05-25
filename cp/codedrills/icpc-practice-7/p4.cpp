#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 1e9 + 7, N = 2e6 + 5;
int di[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dj[8] = {1, 2, 2, 1, -1, -2, -2, -1};

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

// factorial and inverse factorial
int fact[N], invfact[N];
void init()
{
    fact[0] = fact[1] = 1;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
    i--;
    // Fermat's Little Theorem
    // 1/(a! % mod) = a!^mod-2 % mod
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i--; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * 1ll * (i + 1)) % MOD;
}

// NCR
// n!/r!*(n-r)!
int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return mul(fact[n], mul(invfact[r], invfact[n - r]));
}

int solve()
{
    int n, m, k, d = 0;
    cin >> n >> m >> k;
    vector<string> grid(n);
    vector<vector<bool>> vis(n, vector<bool>(m));
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    queue<pii> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'X')
            {
                q.push({i, j});
                vis[i][j] = true;
                mp[0]++;
            }
        }
    }
    while (!q.empty())
    {
        d++;
        int sz = q.size();
        while (sz-- > 0)
        {
            pii cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int i = cur.first + di[dir], j = cur.second + dj[dir];
                if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j])
                {
                    mp[d]++;
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
    }
    int pre = 0, res = 0;
    for (auto x : mp)
    {
        for (int i = 1; i <= min(x.second, k); i++)
            res = add(res, mul(x.first, mul(ncr(x.second, i), ncr(pre, k - i))));
        pre += x.second;
    }
    res = mul(res, power(ncr(n * m, k), MOD - 2, MOD));
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}