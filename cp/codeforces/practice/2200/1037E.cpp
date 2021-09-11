// https://codeforces.com/contest/1037/problem/E
// Trips

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

void solve()
{
    int n, m, k, cur = 0;
    cin >> n >> m >> k;
    vector<set<int>> g(n + 1);
    vector<pii> edges(m);
    vector<int> deg(n + 1), is_friend(n + 1, true), ans;
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;
        g[edges[i].first].insert(edges[i].second);
        g[edges[i].second].insert(edges[i].first);
        deg[edges[i].first]++;
        deg[edges[i].second]++;
    }
    reverse(edges.begin(), edges.end());
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] < k)
        {
            is_friend[i] = false;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int e : g[v])
        {
            if (is_friend[e] && --deg[e] < k)
            {
                is_friend[e] = false;
                q.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        deg[i] = 0;
        if (is_friend[i])
        {
            cur++;
            for (int x : g[i])
                deg[i] += is_friend[x];
        }
    }
    ans.pb(cur);
    for (pii ed : edges)
    {
        g[ed.first].erase(ed.second);
        g[ed.second].erase(ed.first);
        if (is_friend[ed.first] && is_friend[ed.second])
        {
            deg[ed.first]--;
            deg[ed.second]--;
            if (deg[ed.first] < k)
            {
                cur--;
                is_friend[ed.first] = false;
                q.push(ed.first);
            }
            if (deg[ed.second] < k)
            {
                cur--;
                is_friend[ed.second] = false;
                q.push(ed.second);
            }
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (int e : g[v])
                {
                    if (is_friend[e] && --deg[e] < k)
                    {
                        cur--;
                        is_friend[e] = false;
                        q.push(e);
                    }
                }
            }
        }
        ans.pb(cur);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}