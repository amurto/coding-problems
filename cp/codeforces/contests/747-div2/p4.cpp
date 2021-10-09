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

const int N = 2e5 + 5;
vector<int> g[N], nodes;
vector<pii> g1[N], g2[N];
bool vis[N];
int col[N];
void dfs(int cur)
{
    vis[cur] = true;
    nodes.pb(cur);
    for (int e : g[cur])
        if (!vis[e])
            dfs(e);
}

// 0 -> crewmate
// 1 -> imposter
int check(int u, int p, int n)
{
    int cnt = p;
    queue<int> q;
    col[u] = p;
    q.push(u);
    vis[u] = true;
    while (!q.empty())
    {
        int cur = q.front();
        int c = col[cur];
        q.pop();
        for (pii e : g1[cur])
        {
            int tmp = 0;
            if (c == 0)
                tmp = e.second;
            else
                tmp = e.second ^ 1;
            if (vis[e.first])
            {
                if (col[e.first] != tmp)
                    return -1;
            }
            else
            {
                vis[e.first] = true;
                q.push(e.first);
                col[e.first] = tmp;
                cnt += col[e.first];
            }
        }
        for (pii e : g2[cur])
        {
            int tmp = e.second;
            if (c == 1)
                tmp ^= 1;
            if (vis[e.first])
            {
                if (col[e.first] != tmp)
                    return -1;
            }
            else
            {
                vis[e.first] = true;
                q.push(e.first);
                col[e.first] = tmp;
                cnt += col[e.first];
            }
        }
    }
    return cnt;
}

int solve()
{
    int n, m, u, v, res = 0;
    string str;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        g1[i].clear();
        g2[i].clear();
        vis[i] = false;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> str;
        g[u].pb(v);
        g[v].pb(u);
        if (str == "crewmate")
        {
            g1[u].pb({v, 0});
            g2[v].pb({u, 0});
        }
        else
        {
            g1[u].pb({v, 1});
            g2[v].pb({u, 1});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            array<int, 2> c{0, 0};
            for (int p = 0; p < 2; p++)
            {
                for (int x : nodes)
                    vis[x] = false;
                c[p] = check(i, p, n);
            }
            if (c[0] == -1 && c[1] == -1)
                return -1;
            res += max(c[0], c[1]);
            nodes.clear();
        }
    }
    return res;
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