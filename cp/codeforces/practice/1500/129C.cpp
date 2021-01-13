// https://codeforces.com/contest/129/problem/C
// Statues

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 8;
char grid[N][N];
bool vis[N][N][N];
int di[N] = {0, 1, 1, 1, 0, -1, -1, -1}, dj[N] = {1, 1, 0, -1, -1, -1, 0, 1};

bool dfs(int cur, int i, int j)
{
    if (cur == N)
        return true;
    if (vis[cur][i][j])
        return false;
    if (dfs(cur + 1, i, j))
        return true;
    for (int dir = 0; dir < N; dir++)
    {
        int ni = i + di[dir], nj = j + dj[dir];
        if (ni >= 0 && ni < N && nj >= 0 && nj < N && !vis[cur][ni][nj] && dfs(cur + 1, ni, nj))
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                for (int k = 0, m = i; m < N; k++, m++)
                    vis[k][m][j] = true;
            }
        }
    }
    dfs(0, 7, 0) ? cout << "WIN\n" : cout << "LOSE\n";
    return 0;
}