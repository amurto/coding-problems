#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 1;
ll C[N];
vector<int> g[N];
int level[N];
bool vis[N];

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        C[i] = 0;
        level[i] = 0;
        vis[i] = false;
    }
}

void bfs(int root)
{
    queue<int> qq;
    qq.push(root);
    int lev = 0;
    while (!qq.empty())
    {
        int len = qq.size();
        while (len-- > 0)
        {
            int cur = qq.front();
            qq.pop();
            vis[cur] = true;
            level[cur] = lev;
            for (int edge : g[cur])
                if (!vis[edge])
                    qq.push(edge);
        }
        lev++;
    }
}

void dfs(int cur, ll sum)
{
    C[cur] += sum;
    vis[cur] = true;
    for (int edge : g[cur])
        if (!vis[edge])
            dfs(edge, C[cur]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, u, v, q, t, e, root=1;
    ll inc;
    cin >> n;
    init(n);
    vector<pair<int, int>> E(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> E[i].first >> E[i].second;
        g[E[i].first].pb(E[i].second);
        g[E[i].second].pb(E[i].first);
    }
    bfs(root);
    cin >> q;
    while (q-- > 0)
    {
        cin >> t >> e >> inc;
        e--;
        int n1 = E[e].first, n2 = E[e].second;
        if (t == 2)
            swap(n1, n2);
        if (level[n1] < level[n2])
        {
            C[root] += inc;
            C[n2] -= inc;
        }
        else
            C[n1] += inc;
    }
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    dfs(root, 0);

    for (int i = 1; i <= n; i++)
        cout << C[i] << "\n";
    return 0;
}