// https://codeforces.com/contest/652/problem/C
// Foe Pairs

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, m, a, b;
    ll res = 0;
    cin >> n >> m;
    vector<int> p(n + 1), mask(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        mask[p[i]] = i;
    }
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a = mask[a];
        b = mask[b];
        if (a > b)
            swap(a, b);
        g[b].pb(a);
    }
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int e : g[i])
            mx = max(mx, e);
        res += 1ll * (i - mx);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}