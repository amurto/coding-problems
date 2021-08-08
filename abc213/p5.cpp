#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e6 + 5;

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
class cell
{
public:
    int i, j, p, bi, bj;
    cell() {}
    cell(int i, int j, int p, int bi, int bj) : i(i), j(j), p(p), bi(i), bj(bj) {}
    bool operator<(const cell &other) const
    {
        return p > other.p;
    }
};

bool inside_block(int bi, int bj, int i, int j, int h, int w)
{
    if (bi + bj == 0)
        return false;
    int ti[4], tj[4];
    ti[0] = bi;
    tj[0] = bj;
    ti[1] = bi;
    tj[1] = bj + 1;
    ti[2] = bi + 1;
    tj[2] = bj + 1;
    ti[3] = bi + 1;
    tj[3] = bj;
    for (int k = 0; k < 4; k++)
        if (ti[k] > 0 && ti[k] <= h && tj[k] > 0 && tj[k] <= w && ti[k] == i && tj[k] == j)
            return true;
    return false;
}
int solve()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h + 1, vector<char>(w + 1));
    vector<vector<int>> dis(h + 1, vector<int>(w + 1, inf));
    vector<vector<bool>> vis(h + 1, vector<bool>(w + 1));
    dis[1][1] = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> grid[i][j];
    priority_queue<cell> pq;
    pq.push(cell(1, 1, 0, 0, 0));
    while (!pq.empty())
    {
        cell cur = pq.top();
        d(cur.i,cur.j);
        pq.pop();
        if (!vis[cur.i][cur.j])
        {
            vis[cur.i][cur.j] = true;
            for (int dir = 0; dir < 4; dir++)
            {
                int ni = cur.i + di[dir], nj = cur.j + dj[dir];
                if (ni > 0 && ni <= h && nj > 0 && nj <= w)
                {
                    // dont break
                    if (dis[ni][nj] > cur.p && (grid[ni][nj] == '.' || inside_block(cur.bi, cur.bj, ni, nj, h, w)))
                    {
                        dis[ni][nj] = cur.p;
                        pq.push(cell(ni, nj, dis[ni][nj], cur.bi, cur.bj));
                    }
                    // break
                    if (dis[ni][nj] > cur.p + 1)
                    {
                        dis[ni][nj] = cur.p + 1;
                        pq.push(cell(ni, nj, dis[ni][nj], ni, nj));
                        pq.push(cell(ni, nj, dis[ni][nj], ni - 1, nj));
                    }
                }
            }
        }
    }
    return dis[h][w];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}