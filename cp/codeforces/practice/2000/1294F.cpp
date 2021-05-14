// https://codeforces.com/contest/1294/problem/F
// Three Paths on a Tree

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];
int node[N], deep[N];

pii pmax(pii p1, pii p2)
{
    if (p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second))
        swap(p1, p2);
    return p1;
}

pii precompute(int cur, int last)
{
    for (int e : g[cur])
    {
        if (e != last)
        {
            pii p = precompute(e, cur);
            if (p.first >= deep[cur])
            {
                node[cur] = p.second;
                deep[cur] = p.first;
            }
        }
    }
    return {deep[cur] + 1, node[cur]};
}

void dfs(vector<int> &res, int &mx, int cur, int last, pii par)
{
    vector<pii> edge;
    for (int e : g[cur])
    {
        if (e == last)
            edge.pb({0, 0});
        else
            edge.pb({deep[e] + 1, node[e]});
    }
    int sz = edge.size();
    vector<pii> suf(sz + 1);
    for (int i = sz - 1; i >= 0; i--)
        suf[i] = pmax(edge[i], suf[i + 1]);
    pii pre = pmax(par, {0, cur});
    for (int i = 0; i < sz; i++)
    {
        if (g[cur][i] != last)
        {
            pii branch = pmax(pre, suf[i + 1]);
            branch.first++;
            dfs(res, mx, g[cur][i], cur, branch);
            pre = pmax(pre, edge[i]);
        }
    }
    if (par.second >= 0)
        edge.pb(par);
    edge.pb({0, cur});
    sort(edge.rbegin(), edge.rend());
    int sum = 0;
    if (edge.size() >= 3 && edge[2].second != 0)
    {
        sum += edge[0].first + edge[1].first + edge[2].first;
        if (sum >= mx)
        {
            mx = sum;
            res[0] = edge[0].second;
            res[1] = edge[1].second;
            res[2] = edge[2].second;
        }
    }
}

void solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        node[i] = i;
        deep[i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    precompute(1, 1);
    vector<int> res(3);
    int mx = 0;
    dfs(res, mx, 1, -1, {0, -1});
    cout << mx << "\n";
    for (int e : res)
        cout << e << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}