#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int inf = INT_MAX;
map<pii, int> vis;
map<int, vector<int>> cols;
void dfs(int i, int j, int m)
{
    vis[{i, j}] = 1;
    int nxt = inf;
    int ub = upper_bound(cols[j].begin(), cols[j].end(), i) - cols[j].begin();
    if (ub < cols[j].size())
        nxt = cols[j][ub];
    vector<int> seq = {-1, 1};
    for (int d : seq)
    {
        int c = j - d;
        if (cols[c].empty())
            continue;
        int rb = upper_bound(cols[c].begin(), cols[c].end(), i) - cols[c].begin();
        for (int itr = rb; itr < cols[c].size() && cols[c][itr] <= nxt; itr++)
            if (vis[{cols[c][itr], c}] == 0)
                dfs(cols[c][itr], c, m);
    }
}

int solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    vector<pii> pts(m);
    for (int i = 0; i < m; i++)
        cin >> pts[i].first >> pts[i].second;
    sort(pts.begin(), pts.end(), [&](pii &p1, pii &p2)
         {
             if (p1.second == p2.second)
                 return p1.first < p2.first;
             return p1.second < p2.second;
         });
    cols[n].pb(0);
    for (int i = 0; i < m; i++)
        cols[pts[i].second].pb(pts[i].first);
    dfs(0, n, m);
    for (auto c : cols)
        if (!c.second.empty() && vis[{c.second.back(), c.first}] == 1)
            res++;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}