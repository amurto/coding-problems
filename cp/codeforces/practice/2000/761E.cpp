// https://codeforces.com/contest/761/problem/E
// Dasha and Puzzle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 32;
vector<int> g[N];
ll st = 0, pt[N][2];

void dfs(int cur, int last, ll d, int dir)
{
    ll c = 1ll << d;
    ll di[4] = {-c, 0, c, 0};
    ll dj[4] = {0, c, 0, -c};
    vector<int> dirs;
    for (int i = 0; i < 4; i++)
        if (i != dir)
            dirs.pb(i);
    int itr = 0;
    for (int e : g[cur])
    {
        if (e != last)
        {
            pt[e][0] = pt[cur][0] + di[dirs[itr]];
            pt[e][1] = pt[cur][1] + dj[dirs[itr]];
            dfs(e, cur, d - 1, (dirs[itr] + 2) % 4);
            itr++;
        }
    }
}

void solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() > 4)
        {
            cout << "NO\n";
            return;
        }
    }
    pt[1][0] = st;
    pt[1][1] = st;
    dfs(1, 1, n, -1);
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << pt[i][0] << " " << pt[i][1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}