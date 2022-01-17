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

const int N = 3e5 + 5;
int col[N], pos[N], subsum[N];
vector<int> g[N];

void dfs(int cur, int last, int black)
{
    subsum[cur] = col[cur];
    for (int e : g[cur])
    {
        if (e != last)
        {
            dfs(e, cur, black);
            subsum[cur] += subsum[e];
            if (col[e] == 1)
                pos[cur] = 1;
            else if (subsum[e] >= 2)
                pos[cur] = max(pos[cur], pos[e]);
        }
    }
}

void re_root(int cur, int last, int black)
{
    if (last >= 1)
    {
        if (col[last] == 1)
            pos[cur] = 1;
        else if (black - subsum[cur] >= 2)
            pos[cur] = max(pos[cur], pos[last]);
    }
    for (int e : g[cur])
        if (e != last)
            re_root(e, cur, black);
}

void solve()
{
    int n, black = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
        pos[i] = col[i];
        black += col[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1, black);
    re_root(1, -1, black);
    for (int i = 1; i <= n; i++)
        cout << pos[i] << " ";
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