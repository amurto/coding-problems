// https://codeforces.com/contest/576/problem/B
// Invariance of Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1), b(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    vector<vector<int>> g(n + 1), st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            int cur = p[i];
            vector<int> seq;
            seq.pb(i);
            int k = 1;
            while (cur != i)
            {
                vis[cur] = true;
                b[cur] = k;
                k ^= 1;
                seq.pb(cur);
                cur = p[cur];
            }
            st.pb(seq);
        }
    }
    int sz = st.size();
    vector<int> ids(sz);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return st[i1].size() < st[i2].size(); });
    if (st[ids[0]].size() == 1)
    {
        for (int i = 1; i <= n; i++)
            if (i != st[ids[0]][0])
                g[st[ids[0]][0]].pb(i);
    }
    else
    {
        for (int i = 0; i < sz; i++)
        {
            if (((int)st[i].size()) & 1)
            {
                cout << "NO\n";
                return;
            }
        }
        if (st[ids[0]].size() > 2)
        {
            cout << "NO\n";
            return;
        }
        vector<int> nodes(2);
        nodes[0] = st[ids[0]][0];
        nodes[1] = st[ids[0]][1];
        for (int i = 1; i <= n; i++)
            if (i != nodes[0] && i != nodes[1])
                g[nodes[b[i]]].pb(i);
        g[nodes[0]].pb(nodes[1]);
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        for (int e : g[i])
            cout << i << " " << e << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}