// https://codeforces.com/contest/498/problem/C
// Array and Operations

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

class node
{
public:
    int v, f, p, id;
    node() {}
    node(int v, int f, int p, int id) : v(v), f(f), p(p), id(id) {}
};

const int N = 10005;
vector<int> g[N];
bool vis[N];
int mt[N];
vector<node> nodes;

void factorise(int cur, int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int p = 0, sz = (int)nodes.size();
            while (x % i == 0)
            {
                x /= i;
                nodes.pb(node(cur, i, p, sz));
                sz++;
                p++;
            }
        }
        if (i > 2)
            i++;
    }
    if (x > 1)
        nodes.pb(node(cur, x, 0, (int)nodes.size()));
}

bool try_kuhn(int cur)
{
    if (vis[cur])
        return false;
    vis[cur] = true;
    for (int e : g[cur])
    {
        if (mt[e] == -1 || try_kuhn(mt[e]))
        {
            mt[e] = cur;
            return true;
        }
    }
    return false;
}

int solve()
{
    int n, m, op = 0;
    cin >> n >> m;
    vector<int> arr(n + 1);
    vector<pii> edge_seq(m), edges;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        factorise(i, arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> edge_seq[i].first >> edge_seq[i].second;
        if (edge_seq[i].first % 2 == 0)
            swap(edge_seq[i].first, edge_seq[i].second);
    }
    vector<vector<node>> st(n + 1);
    for (node u : nodes)
        st[u.v].pb(u);
    for (pii e : edge_seq)
        for (node x : st[e.first])
            for (node y : st[e.second])
                if (x.f == y.f)
                    edges.pb({x.id, y.id});
    for (pii e : edges)
        g[e.first].pb(e.second);
    int sz = nodes.size();
    for (int i = 0; i < sz; i++)
        mt[i] = -1;
    for (int i = 0; i < sz; i++)
    {
        for (int i = 0; i < sz; i++)
            vis[i] = false;
        if (nodes[i].v & 1)
            try_kuhn(i);
    }
    for (int i = 0; i < sz; i++)
        if (mt[i] != -1)
            op++;
    return op;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}