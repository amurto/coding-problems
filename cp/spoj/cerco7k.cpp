// https://www.spoj.com/problems/CERC07K/
// CERC07K - Key Task

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
unordered_map<char, int> mp;

void init()
{
    string door = "BYRG", key = "byrg";
    for (int i = 0; i < 4; i++)
        mp[door[i]] = mp[key[i]] = i;
}

int encrypt(char ch, int mask)
{
    if (ch == 'b' || ch == 'y' || ch == 'r' || ch == 'g')
        mask |= (1 << mp[ch]);
    return mask;
}

bool possible(char ch, int mask)
{
    if (ch == '#')
        return false;
    if (ch == 'B' || ch == 'Y' || ch == 'R' || ch == 'G')
        return (mask & (1 << mp[ch]));
    return true;
}
int bfs(vector<vector<char>> &maze, int r, int c, int si, int sj)
{
    bool vis[r][c][16];
    memset(vis, false, sizeof(vis));
    int m = 1;
    queue<piii> q;
    q.push({0, {si, sj}});
    vis[si][sj][0] = true;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            int mask = q.front().first;
            pair<int, int> from = q.front().second;
            mask = encrypt(maze[from.first][from.second], mask);
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int i = from.first + di[dir], j = from.second + dj[dir];
                if (i < 0 || i >= maze.size() || j < 0 || j >= maze[0].size())
                    continue;
                if (maze[i][j] == 'X')
                    return m;
                if (!vis[i][j][mask] && possible(maze[i][j], mask))
                {
                    vis[i][j][mask] = true;
                    q.push({mask, {i, j}});
                }
            }
        }
        m++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int r, c, si, sj;
    while (cin >> r >> c && r + c > 0)
    {
        vector<vector<char>> maze(r, vector<char>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> maze[i][j];
                if (maze[i][j] == '*')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        int res = bfs(maze, r, c, si, sj);
        if (res >= 0)
            cout << "Escape possible in " << res << " steps.\n";
        else
            cout << "The poor student is trapped!\n";
    }
}