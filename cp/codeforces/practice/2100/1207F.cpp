// https://codeforces.com/contest/1207/problem/F
// Remainder Problem

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 5e5 + 1;
void solve()
{
    int q;
    cin >> q;
    vector<int> t(q), x(q), y(q);
    set<pii> st;
    vector<bool> vis(N);
    for (int i = 0; i < q; i++)
    {
        cin >> t[i] >> x[i] >> y[i];
        if (t[i] == 1)
            vis[x[i]] = true;
        else
            st.insert({x[i], y[i]});
    }
    vector<pii> qs(st.begin(), st.end());
    vector<vector<int>> g(N);
    for (int j = 0; j < qs.size(); j++)
        for (int i = qs[j].second; i < N; i += qs[j].first)
            if (vis[i])
                g[i].pb(j);
    int s = st.size();
    vector<ll> res(s);
    for (int i = 0; i < q; i++)
    {
        if (t[i] == 1)
            for (int id : g[x[i]])
                res[id] += 1ll * y[i];
        else
        {
            int id = lower_bound(qs.begin(), qs.end(), make_pair(x[i], y[i])) - qs.begin();
            cout << res[id] << "\n";
        }
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