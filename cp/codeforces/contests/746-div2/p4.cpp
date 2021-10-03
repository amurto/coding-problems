#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];
// Entry and Exit time for Segment Tree
int vis1[N], vis2[N], ver[N], par[N];
int dfs(int cur, int last, int t)
{
    par[cur] = last;
    vis1[cur] = vis2[cur] = t;
    ver[t] = cur;
    for (int e : g[cur])
        if (e != last)
            vis2[cur] = max(vis2[cur], dfs(e, cur, vis2[cur] + 1));
    return vis2[cur];
}

int query(vector<int> &nodes)
{
    int k = (int)nodes.size();
    cout << "? " << k << " ";
    for (int x : nodes)
        cout << x << " ";
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
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
    vector<int> nodes;
    for (int i = 1; i <= n; i++)
        nodes.pb(i);
    int mx = query(nodes);
    dfs(1, 1, 0);
    int low = 1, high = n - 1, id = n - 1, a = 0, b = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        vector<int> tmp;
        for (int i = 0; i <= mid; i++)
            tmp.pb(ver[i]);
        int q = query(tmp);
        if (q >= mx)
        {
            id = min(id, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    a = ver[id];
    b = par[a];
    cout << "! " << a << " " << b << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}