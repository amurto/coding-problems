#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int h, w, di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
    char c;
    cin >> h >> w;
    vector<vector<pair<int, int>>> alphabet(26);
    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<bool>> vis(h, vector<bool>(w));
    pair<int, int> cur = {0, 0};
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                cur.first = i;
                cur.second = j;
            }
            else if (grid[i][j] >= 'a' && grid[i][j] <= 'z')
            {
                alphabet[grid[i][j] - 'a'].pb({i, j});
            }
        }
    }
    int time = 1;
    queue<pair<int, int>> q;
    q.push(cur);
    vis[cur.first][cur.second] = true;
    while (!q.empty())
    {
        int len = q.size();
        while (len-- > 0)
        {
            pair<int, int> from = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int i = from.first + di[dir], j = from.second + dj[dir];
                if (i >= 0 && i < h && j >= 0 && j < w && grid[i][j] != '#' && !vis[i][j])
                {
                    if (grid[i][j] == 'G')
                        return time;
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
            if (grid[from.first][from.second] >= 'a' && grid[from.first][from.second] <= 'z')
            {
                for (pair<int, int> tel : alphabet[grid[from.first][from.second] - 'a'])
                {
                    if (grid[tel.first][tel.second] == 'G')
                        return time;
                    if (vis[tel.first][tel.second])
                        continue;
                    vis[tel.first][tel.second] = true;
                    q.push(tel);
                }
            }
        }
        time++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}