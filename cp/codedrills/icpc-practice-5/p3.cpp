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

int f(vector<vector<int>> &g, vector<int> &arr, vector<int> &mx, int cur, int last)
{
    mx[cur] = arr[cur];
    if (g[cur].size() == 1 && g[cur][0] == last)
        return mx[cur];
    for (int e : g[cur])
    {
        if (e == last)
            continue;
        mx[cur] = max(mx[cur], f(g, arr, mx, e, cur));
    }
    return mx[cur];
}

void dfs(vector<vector<int>> &g, vector<int> &arr, vector<int> &mx, int &p, int px, int cur, int last)
{
    if (g[cur].size() == 1 && g[cur][0] == last)
        return;
    px = max(arr[cur], px);
    vector<int> seq;
    for (int e : g[cur])
    {
        if (e == last)
        {
            seq.pb(px);
            continue;
        }
        seq.pb(mx[e]);
    }
    int sz = seq.size();
    vector<int> suf(sz + 1);
    for (int i = sz - 1; i >= 0; i--)
        suf[i] = max(seq[i], suf[i + 1]);
    int pre = px;
    for (int i = 0; i < sz; i++)
    {
        if (g[cur][i] == last)
        {
            pre = max(pre, seq[i]);
            continue;
        }
        dfs(g, arr, mx, p, max(pre, suf[i + 1]), g[cur][i], cur);
        p = add(p, abs(max(pre, suf[i + 1]) - seq[i]));
        pre = max(pre, seq[i]);
    }
}

ll solve()
{
    int n, u, v, p = 0;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> arr(n + 1), mx(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    f(g, arr, mx, 1, -1);
    dfs(g, arr, mx, p, 0, 1, -1);
    p = mul(p, power(n - 1, MOD - 2, MOD));
    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}