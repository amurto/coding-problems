// Finding cycles in a cactus
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 3e5 + 5;
vector<int> g[N];

void find_cycles(vector<pii> &ivs, vector<int> &last, vector<int> &vis, int cur, int par)
{

    vis[cur] = 2;
    last[cur] = par;
    for (int e : g[cur])
    {
        if (e != par)
        {
            if (vis[e] == 2)
            {

                int l = e, r = e, node = cur;
                while (node != e)
                {
                    l = min(l, node);
                    r = max(r, node);
                    node = last[node];
                }
                ivs.pb({l, r});
            }
            else if (vis[e] == 0)
                find_cycles(ivs, last, vis, e, cur);
        }
    }
    vis[cur] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> last(n + 1), right(n + 1), vis(n + 1);
    vector<pii> ivs;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0)
            find_cycles(ivs, last, vis, i, 0);
    // ivs have {min, max} pairs of cycle
    return 0;
}