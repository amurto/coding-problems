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

const int MOD = 1e9 + 7, N = 2e5 + 5, LGN = 19, Q = 142857001, D = 1e6;
vector<int> g[N];
int P[N], A[N], B[N], AN[N], BN[N], H[N], NH[N], up[N][LGN + 1], tin[N], tout[N], dep[N], timer = 0;
int tmp1[N], tmp2[N];
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

void dfs(int cur, int last, int dd)
{
    if (cur == 1)
    {
        H[cur] = A[cur];
        NH[cur] = AN[cur];
    }
    else
    {
        H[cur] = add(mul(H[P[cur]], A[cur]), mul(NH[P[cur]], B[cur]));
        NH[cur] = add(mul(H[P[cur]], AN[cur]), mul(NH[P[cur]], BN[cur]));
    }
    tin[cur] = ++timer;
    dep[cur] = dd;
    up[cur][0] = P[cur];
    for (int i = 1; i <= LGN; i++)
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    for (int e : g[cur])
        dfs(e, cur, dd + 1);
    tout[cur] = timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LGN; i >= 0; i--)
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

int calc(int u, int v, int h)
{
    int c = v;
    vector<int> st;
    while (c != u)
    {
        st.pb(c);
        c = P[c];
    }
    reverse(st.begin(), st.end());
    if (h)
    {
        tmp1[u] = 1, tmp2[u] = 0;
    }
    else
    {
        tmp1[u] = 0, tmp2[u] = 1;
    }
    for (int x : st)
    {
        tmp1[x] = add(mul(tmp1[P[x]], A[x]), mul(tmp2[P[x]], B[x]));
        tmp2[x] = add(mul(tmp1[P[x]], AN[x]), mul(tmp2[P[x]], BN[x]));
    }
    return tmp1[v];
}
void solve(int tc)
{
    timer = 0;
    int n, q;
    cin >> n >> q >> A[1];
    AN[1] = D - A[1];
    A[1] = mul(A[1], Q);
    AN[1] = mul(AN[1], Q);
    B[1] = 0;
    BN[1] = 0;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    P[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> P[i] >> A[i] >> B[i];
        AN[i] = D - A[i];
        BN[i] = D - B[i];
        A[i] = mul(A[i], Q);
        B[i] = mul(B[i], Q);
        AN[i] = mul(AN[i], Q);
        BN[i] = mul(BN[i], Q);
        g[P[i]].pb(i);
    }
    dfs(1, 1, 0);
    vector<int> res(q);
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (dep[u] > dep[v])
            swap(u, v);
        int k = lca(u, v);
        // if (k == u)
        // {
        //     // u is the ancestor
        //     // find probability that given event u occurs, event v occurs
        //     res[i] = mul(H[u], calc(u, v, 1));
        // }
        // else
        // {
        int a1 = calc(k, u, 1), a2 = calc(k, v, 1);
        int b1 = calc(k, u, 0), b2 = calc(k, v, 0);
        res[i] = add(mul(H[k], mul(a1, a2)), mul(NH[k], mul(b1, b2)));
        //}
    }
    cout << "Case #" << tc << ": ";
    for (int i = 0; i < q; i++)
        cout << res[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve(tc);
    return 0;
}