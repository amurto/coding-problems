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
    int r, g, b;
    cin >> r >> g >> b;
    int n = r + g + b;
    vector<char> col(n + 1, 'B');
    vector<vector<int>> adj(n + 1);
    vector<pii> edges;
    if (r + g < b)
    {
        cout << "-1\n";
        return;
    }
    if (min(r, g) == 1)
    {
        if (r == 1)
        {
            col[1] = 'R';
            for (int j = 2; j < 2 + g; j++)
            {
                col[j] = 'G';
                adj[1].pb(j);
            }
        }
        else
        {
            col[1] = 'G';
            for (int j = 2; j < 2 + r; j++)
            {
                col[j] = 'R';
                adj[1].pb(j);
            }
        }
        adj[1].pb(r + g + 1);
        for (int i = r + g + 2, j = 2; i <= n; i++, j++)
            adj[j].pb(i);
    }
    else
    {
        vector<int> nodes;
        adj[1].pb(2);
        col[1] = 'R';
        col[2] = 'G';
        for (int i = 3; i < 3 + r - 1; i++)
        {
            col[i] = 'R';
            nodes.pb(i);
            adj[2].pb(i);
        }
        for (int i = r + 2; i < r + 2 + g - 1; i++)
        {
            col[i] = 'G';
            nodes.pb(i);
            adj[1].pb(i);
        }
        nodes.pb(1);
        nodes.pb(2);
        for (int i = r + g + 1, itr = 0; i <= n; i++, itr++)
            adj[nodes[itr]].pb(i);
    }
    for (int i = 1; i <= n; i++)
        for (int e : adj[i])
            if (e > i)
                edges.pb({i, e});
    for (int i = 1; i <= n; i++)
        cout << col[i];

    cout << "\n";
    for (pii e : edges)
        cout << e.first << " " << e.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}