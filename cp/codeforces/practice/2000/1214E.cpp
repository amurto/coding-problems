// https://codeforces.com/contest/1214/problem/E
// Petya and Construction Set

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(2 * n + 1);
    vector<int> d(n), seq(n), vis(n), last(n + 1);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    iota(seq.begin(), seq.end(), 0);
    sort(seq.begin(), seq.end(), [&](int &i1, int &i2)
         { return d[i1] > d[i2]; });
    for (int i = 0; i < n; i++)
        vis[i] = 2 * (seq[i] + 1) - 1;
    for (int i = 1; i < n; i++)
        g[vis[i]].pb(vis[i - 1]);
    last[0] = vis.back();
    for (int i = 0; i < n; i++)
    {
        int node = 2 * (seq[i] + 1);
        int dis = d[seq[i]];
        if (i + dis >= n)
        {
            int rem = i + dis - n + 1;
            g[last[rem - 1]].pb(node);
            last[rem] = node;
        }
        else
            g[vis[i + dis - 1]].pb(node);
    }
    for (int i = 1; i <= 2 * n; i++)
        for (int e : g[i])
            cout << i << " " << e << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}