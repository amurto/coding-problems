#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
// Entry and Exit time for Segment Tree
vector<int> vis1(N), vis2(N), dep(N);
int dfs(vector<vector<int>> &g, vector<int> &arr, int cur, int last, int t, int lvl)
{
    vis1[cur] = vis2[cur] = t;
    dep[cur] = lvl;
    if (g[cur].size() == 1 && g[cur][0] == last)
        return vis1[cur];
    int mx = vis1[cur];
    for (int e : g[cur])
    {
        if (e == last)
            continue;
        vis2[cur] = dfs(g, arr, e, cur, vis2[cur] + 1, lvl + 1);
    }
    return vis2[cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}