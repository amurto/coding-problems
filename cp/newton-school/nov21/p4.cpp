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

const int inf = 1e9, N = 3005;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int dis[N][N][2];
class cell
{
public:
    int i, j, p;
    cell() {}
    cell(int i, int j, int p) : i(i), j(j), p(p) {}
};

int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> row(n, vector<int>(2)), col(m, vector<int>(2));
    for (int i = 0; i < k; i++)
    {
        int x, y;
        char ch;
        cin >> x >> y >> ch;
        x--;
        y--;
        if (ch == 'R')
        {
            row[x][0] = 1;
            col[y][1] = 1;
        }
        else
        {
            row[x][1] = 1;
            col[y][0] = 1;
        }
    }
    memset(dis, -1, sizeof(dis));
    queue<cell> q;
    dis[0][0][0] = 0;
    q.push(cell(0, 0, 0));
    while (!q.empty())
    {
        int sz = (int)q.size();
        while (sz > 0)
        {
            cell cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int ni = cur.i + di[dir], nj = cur.j + dj[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && row[ni][cur.p ^ 1] == 0 && col[nj][cur.p ^ 1] == 0 && dis[ni][nj][cur.p ^ 1] == -1)
                {
                    dis[ni][nj][cur.p ^ 1] = dis[cur.i][cur.j][cur.p] + 1;
                    q.push(cell(ni, nj, cur.p ^ 1));
                }
            }
            sz--;
        }
    }
    ll mn = inf, d1 = dis[n - 1][m - 1][0], d2 = dis[n - 1][m - 1][1];
    if (d1 >= 0 && d1 < mn)
        mn = d1;
    if (d2 >= 0 && d2 < mn)
        mn = d2;
    return mn >= inf ? -1 : mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}