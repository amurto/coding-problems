// 0-1 BFS
// Can be used when weights are of two types

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 2e6;
int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// 0-1 BFS for grid
int bfs(vector<vector<char>> &grid, int r, int c, int si, int sj, int ti, int tj)
{
    vector<vector<int>> dis(r, vector<int>(c, inf));
    deque<pair<int, int>> dq;
    dis[si][sj] = 0;
    dq.push_back({si, sj});
    while (!dq.empty())
    {
        pair<int, int> from = dq.front();
        int d = dis[from.first][from.second];
        dq.pop_front();
        for (int dir = 0; dir < 8; dir++)
        {
            int i = from.first + di[dir], j = from.second + dj[dir];
            if (i < 0 || i >= r || j < 0 || j >= c)
                continue;
            int f = (dir != grid[from.first][from.second] - '0');
            if (d + f < dis[i][j])
            {
                dis[i][j] = d + f;
                f ? dq.push_back({i, j}) : dq.push_front({i, j});
            }
        }
    }
    return dis[ti][tj];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, r, c, si, sj, ti, tj;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    cin >> n;
    while (n-- > 0)
    {
        cin >> si >> sj >> ti >> tj;
        si--;
        sj--;
        ti--;
        tj--;
        cout << bfs(grid, r, c, si, sj, ti, tj) << "\n";
    }
    return 0;
}