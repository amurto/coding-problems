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

const int inf = 1e9 + 7;
struct node
{
    int x = 0, y = 0, dir = 0, dis = 0;
    node(int tx, int ty, int t_dir, int t_dis)
    {
        x = tx;
        y = ty;
        dir = t_dir;
        dis = t_dis;
    }
    bool operator<(const node &other) const
    {
        return dis > other.dis;
    }
};

int solve()
{
    int n, ax, ay, bx, by, res = inf;
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
    cin >> n >> ax >> ay >> bx >> by;
    ax--;
    ay--;
    bx--;
    by--;
    vector<string> grid(n);
    vector<vector<vector<int>>> dis(4, vector<vector<int>>(n, vector<int>(n, inf)));
    vector<vector<vector<bool>>> vis(4, vector<vector<bool>>(n, vector<bool>(n)));
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    priority_queue<node> pq;
    for (int t = 0; t < 4; t++)
    {
        dis[t][ax][ay] = 0;
        pq.push(node(ax, ay, t, 0));
    }
    while (!pq.empty())
    {
        node cur = pq.top();
        pq.pop();
        if (!vis[cur.dir][cur.x][cur.y])
        {
            vis[cur.dir][cur.x][cur.y] = true;
            for (int dir = 0; dir < 4; dir++)
            {
                int tx = cur.x + dx[dir], ty = cur.y + dy[dir];
                if (tx >= 0 && tx < n && ty >= 0 && ty < n && grid[tx][ty] == '.' && !vis[dir][tx][ty] && cur.dis + (cur.dir != dir) < dis[dir][tx][ty])
                {
                    dis[dir][tx][ty] = cur.dis + (cur.dir != dir);
                    pq.push(node(tx, ty, dir, dis[dir][tx][ty]));
                }
            }
        }
    }
    for (int t = 0; t < 4; t++)
        res = min(res, dis[t][bx][by]);
    return res >= inf ? -1 : res + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}