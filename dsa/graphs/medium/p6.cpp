// https://practice.geeksforgeeks.org/problems/steps-by-knight/0
// Steps by Knight

#include <bits/stdc++.h>
using namespace std;

int minStepsByKnight(int n, int ki, int kj, int ti, int tj)
{
    if (ki == ti && kj == tj)
        return 0;

    int moves = 0, di[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dj[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    queue<pair<int, int>> q;
    q.push({ki, kj});

    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
    while (!q.empty())
    {
        moves++;
        int size = q.size();
        while (size-- > 0)
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (vis[cur.first][cur.second])
                continue;
            vis[cur.first][cur.second] = true;
            for (int dir = 0; dir < 8; dir++)
            {
                int i = cur.first + di[dir], j = cur.second + dj[dir];
                if (i > 0 && i <= n && j > 0 && j <= n && !vis[i][j])
                {
                    if (i == ti && j == tj)
                        return moves;
                    q.push({i, j});
                }
            }
        }
    }
    return moves;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, ki, kj, ti, tj;
        cin >> n >> ki >> kj >> ti >> tj;
        cout << minStepsByKnight(n, ki, kj, ti, tj) << "\n";
    }
    return 0;
}