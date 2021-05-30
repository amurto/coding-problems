#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int inf = 2e9 + 20;
map<pii, int> ids;
map<int, int> mask;
vector<vector<int>> cols;
void dfs(vector<bool> &vis, int i, int j, int m)
{
    vis[ids[{i, j}]] = true;
    int nxt = inf;
    int tmp = mask[j];
    int ub = upper_bound(cols[tmp].begin(), cols[tmp].end(), i) - cols[tmp].begin();
    if (ub < cols[tmp].size())
        nxt = cols[tmp][ub];
    vector<int> seq = {-1, 1};
    for (int d : seq)
    {
        int c = j - d;
        if (mask[c] == 0)
            continue;
        int msk = mask[c];
        int ub = upper_bound(cols[msk].begin(), cols[msk].end(), i) - cols[msk].begin();
        for (int itr = ub; itr < cols[msk].size() && cols[msk][itr] <= nxt; itr++)
            if (!vis[ids[{cols[msk][itr], c}]])
                dfs(vis, cols[msk][itr], c, m);
    }
}
int solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> ys;
    vector<pii> pts(m + 1);
    vector<bool> vis(m + 1);
    ys.pb(-1);
    for (int i = 1; i <= m; i++)
    {
        cin >> pts[i].first >> pts[i].second;
        ys.pb(pts[i].second);
    }
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    int sz = ys.size();
    cols.resize(sz);
    for (int i = 0; i < sz; i++)
        mask[ys[i]] = i;
    sort(pts.begin(), pts.end());
    for (int i = 1; i <= m; i++)
    {
        ids[{pts[i].first, pts[i].second}] = i;
        cols[mask[pts[i].second]].pb(pts[i].first);
    }
    // for (int i = 0; i < sz; i++)
    //     if (!cols[i].empty())
    //         cout << cols[i].size() << "\n";
    dfs(vis, 0, n, m);
    for (int i = 0; i < sz; i++)
        if (!cols[i].empty())
            res += (vis[ids[{cols[i].back(), ys[i]}]]);
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