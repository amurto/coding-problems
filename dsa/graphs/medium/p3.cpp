// https://leetcode.com/problems/rotting-oranges/
// Rotting Oranges

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size(), di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0}, i, j, minutes = -1, fresh = 0;

    // multisource bfs
    queue<pair<int, int>> Q;

    // put all rotten oranges into queue
    // count fresh oranges
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (grid[i][j] == 2)
                Q.push({i, j});
            else if (grid[i][j] == 1)
                fresh++;

    if (fresh == 0)
        return 0;

    while (!Q.empty())
    {
        int oranges = Q.size();
        while (oranges-- > 0)
        {
            i = Q.front().first;
            j = Q.front().second;
            Q.pop();
            for (int dir = 0; dir < 4; dir++)
                if (i + di[dir] >= 0 && i + di[dir] < n && j + dj[dir] >= 0 && j + dj[dir] < m && grid[i + di[dir]][j + dj[dir]] == 1)
                {
                    grid[i + di[dir]][j + dj[dir]] = 2;
                    Q.push({i + di[dir], j + dj[dir]});
                    fresh--;
                }
        }
        minutes++;
    }

    // if any fresh orange remaining, return -1
    return fresh == 0 ? minutes : -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    cout << orangesRotting(grid) << "\n";
    return 0;
}