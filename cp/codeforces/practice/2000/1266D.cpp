// https://codeforces.com/contest/1266/problem/D
// Decreasing Debts

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, u, v;
    cin >> n >> m;
    ll d;
    vector<ll> b(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> d;
        b[u] -= d;
        b[v] += d;
    }
    vector<pair<int, ll>> st;
    vector<pair<pair<int, int>, ll>> res;
    for (int i = 1; i <= n; i++)
        if (b[i] < 0)
            st.pb({i, -b[i]});
    for (int i = 1; i <= n; i++)
    {
        while (b[i] > 0)
        {
            ll mn = min(b[i], st.back().second);
            res.pb({{st.back().first, i}, mn});
            b[i] -= mn;
            st.back().second -= mn;
            if (st.back().second == 0)
                st.pop_back();
        }
    }
    cout << res.size() << "\n";
    for (pair<pair<int, int>, ll> p : res)
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}