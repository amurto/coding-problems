// https://codeforces.com/contest/963/problem/B
// Destruction of a Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
set<int> g[N];
vector<int> seq;
vector<bool> vis(N);

bool dfs(int cur, int last)
{
    vector<int> del;
    for (int e : g[cur])
        if (e != last && dfs(e, cur))
            del.pb(e);
    for (int d : del)
        g[cur].erase(d);
    if (g[cur].size() % 2 == 0)
    {
        for (int e : g[cur])
            if (e != last)
                g[e].erase(cur);
        seq.pb(cur);
        g[cur].clear();
        vis[cur] = true;
    }
    return vis[cur];
}

void solve()
{
    int n, p;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        if (p > 0)
        {
            g[i].insert(p);
            g[p].insert(i);
        }
    }
    if (n % 2 == 0)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, i);
    cout << "YES\n";
    for (int s : seq)
        cout << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}