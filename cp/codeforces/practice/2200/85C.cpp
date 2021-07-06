// https://codeforces.com/contest/85/problem/C
// Petya and Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 1e5 + 5;
vector<int> g[N];
int d[N][2], val[N], dep[N];
ll num[N], den[N];

void successor(int cur, int lvl)
{
    dep[cur] = lvl;
    if (g[cur].empty())
        d[cur][0] = d[cur][1] = cur;
    if (!g[cur].empty())
    {
        for (int e : g[cur])
            successor(e, lvl + 1);
        d[cur][0] = d[g[cur][0]][0];
        d[cur][1] = d[g[cur][1]][1];
    }
}

void calc(int l, int r, int v)
{
    if (r < l)
        return;
    num[l] += 1ll * v;
    num[r + 1] -= 1ll * v;
}

void dfs(vector<int> &arr, int l, int r, int cur)
{
    if (r < l)
        return;
    if (g[cur].empty())
    {
        den[l] += 1ll * dep[cur];
        den[r + 1] -= 1ll * dep[cur];
        return;
    }
    int m2 = lower_bound(arr.begin(), arr.end(), val[cur]) - arr.begin();
    int m1 = m2 - 1;
    calc(l, m1, val[d[g[cur][1]][0]]);
    calc(m2, r, val[d[g[cur][0]][1]]);
    dfs(arr, l, m1, g[cur][0]);
    dfs(arr, m2, r, g[cur][1]);
}

void solve()
{
    int n, k, p, rt = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p >> val[i];
        if (p == -1)
            rt = i;
        if (p != -1)
            g[p].pb(i);
    }
    cin >> k;
    vector<int> arr(k), ids(k);
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return arr[i1] < arr[i2]; });
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
        if (!g[i].empty() && val[g[i][0]] > val[g[i][1]])
            swap(g[i][0], g[i][1]);
    successor(rt, 0);
    for (int i = 0; i <= k; i++)
        num[i] = den[i] = 0;
    dfs(arr, 0, k - 1, rt);
    for (int i = 1; i < k; i++)
    {
        num[i] += num[i - 1];
        den[i] += den[i - 1];
    }
    vector<double> res(k);
    for (int i = 0; i < k; i++)
        res[ids[i]] = (1.0 * num[i]) / (1.0 * den[i]);
    for (int i = 0; i < k; i++)
        cout << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    solve();
    return 0;
}