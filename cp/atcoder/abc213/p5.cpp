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

const int inf = 1e6 + 5;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
int f(int i, int j)
{
    return abs(i) + abs(j);
}

bool valid(int ni, int nj, int h, int w)
{
    return ni > 0 && ni <= h && nj > 0 && nj <= w;
}

int solve()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h + 1, vector<char>(w + 1));
    vector<vector<int>> dis(h + 1, vector<int>(w + 1, inf));
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> grid[i][j];

    deque<pii> dq;
    dis[1][1] = 0;
    dq.pb({1, 1});
    while (!dq.empty())
    {
        pii cur = dq.front();
        dq.pop_front();
        for (int dir = 0; dir < 4; dir++)
        {
            int ni = cur.first + di[dir], nj = cur.second + dj[dir];
            if (valid(ni, nj, h, w) && grid[ni][nj] == '.' && dis[ni][nj] > dis[cur.first][cur.second])
            {
                dis[ni][nj] = dis[cur.first][cur.second];
                dq.push_front({ni, nj});
            }
        }
        for (int i = -2; i <= 2; i++)
        {
            for (int j = -2; j <= 2; j++)
            {
                if (f(i, j) > 0 && f(i, j) < 4)
                {
                    int ni = cur.first + i, nj = cur.second + j;
                    if (valid(ni, nj, h, w) && dis[ni][nj] > dis[cur.first][cur.second] + 1)
                    {
                        dis[ni][nj] = dis[cur.first][cur.second] + 1;
                        dq.push_back({ni, nj});
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