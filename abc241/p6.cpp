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

// 0 -> up
// 1 -> right
// 2 -> down
// 3 -> left
const int inf = 1e9 + 7;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};

int get_id(vector<pii> &pts, int x, int y)
{
    int id = lower_bound(pts.begin(), pts.end(), pii(x, y)) - pts.begin();
    if (id >= (int)pts.size())
        return -1;
    return id;
}

int solve()
{
    int h, w, n, sx, sy, gx, gy, res = inf;
    cin >> h >> w >> n >> sx >> sy >> gx >> gy;
    vector<int> x(n), y(n);
    map<int, set<int>> x_ids, y_ids;
    vector<pii> pts;
    x[0] = sx;
    y[0] = sy;
    pts.pb({sx, sy});
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        for (int dir = 0; dir < 4; dir++)
        {
            int tx = x[i] + di[dir], ty = y[i] + dj[dir];
            if (tx >= 1 && tx <= h && ty >= 1 && ty <= w)
                pts.pb({tx, ty});
        }
        x_ids[x[i]].insert(y[i]);
        y_ids[y[i]].insert(x[i]);
    }
    for (auto v : x_ids)
    {
        x_ids[v.first].insert(-inf);
        x_ids[v.first].insert(inf);
    }
    for (auto v : y_ids)
    {
        y_ids[v.first].insert(-inf);
        y_ids[v.first].insert(inf);
    }
    sort(pts.begin(), pts.end());
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
    int sz = (int)pts.size();
    for (int i = 0; i < sz; i++)
        if (pts[i].first == sx && pts[i].second == sy)
            swap(pts[0], pts[i]);
    vector<vector<int>> g(sz, vector<int>(4, -1));
    for (int i = 0; i < sz; i++)
    {
        int vx = pts[i].first, vy = pts[i].second;
        auto it0 = y_ids[vy].lower_bound(vy);
        it0--;
        if (*it0 > -inf)
        {
            g[i][0]=get_id(pts,)
        }
    }
    vector<bool> vis(sz);
    vector<int> dis(sz, inf);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    dis[0] = 0;
    while (!q.empty())
    {
        int len = (int)q.size();
        while (len > 0)
        {
            int cur = q.front();
            if (pts[cur].first == gx && pts[cur].second == gy)
                return dis[cur] + 1;
            q.pop();
            for (int e : g[cur])
            {
                if (e != -1)
                {
                    if (!vis[e])
                    {
                        dis[e] = dis[cur] + 1;
                        vis[e] = true;
                        q.push(e);
                    }
                }
            }
            len--;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}