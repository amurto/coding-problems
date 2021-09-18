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

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
vector<vector<int>> mat(4, vector<int>(4)), grid(4, vector<int>(4)), vis(4, vector<int>(4));

int dfs1(int i, int j)
{
    int ans = 1;
    vis[i][j] = 1;
    for (int dir = 0; dir < 4; dir++)
    {
        int ti = i + di[dir], tj = j + dj[dir];
        if (ti >= 0 && ti < 4 && tj >= 0 && tj < 4 && grid[ti][tj] && !vis[ti][tj])
            ans += dfs1(ti, tj);
    }
    return ans;
}

void dfs2(int i, int j)
{
    vis[i][j] = true;
    for (int dir = 0; dir < 4; dir++)
    {
        int ti = i + di[dir], tj = j + dj[dir];
        if (ti >= 0 && ti < 4 && tj >= 0 && tj < 4 && !vis[ti][tj])
            dfs2(ti, tj);
    }
}

void clear()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            grid[i][j] = vis[i][j] = 0;
}

void display()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

int solve()
{
    int res = 0, submask = 0;
    for (int i = 0, cur = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++, cur++)
        {
            mat[i][j] = 0;
            cin >> mat[i][j];
            if (mat[i][j])
                submask |= (1 << cur);
        }
    }
    int b = 16;
    for (int mask = submask; mask < (1 << b); mask = (mask + 1) | submask)
    {
        clear();
        int cnt = __builtin_popcount(mask);
        for (int i = 0, cur = 0; i < 4; i++)
            for (int j = 0; j < 4; j++, cur++)
                if ((mask >> cur) & 1)
                    grid[i][j] = 1;
        bool f = false, val = false;
        for (int i = 0; !f && i < 4; i++)
        {
            for (int j = 0; !f && j < 4; j++)
            {
                if (grid[i][j])
                {
                    f = true;
                    if (dfs1(i, j) == cnt)
                        val = true;
                }
            }
        }
        if (val)
        {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    if ((i == 0 || i == 3 || j == 0 || j == 3) && !vis[i][j])
                        dfs2(i, j);
            int vis_cnt = 0;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    vis_cnt += vis[i][j];
            if (vis_cnt == 16)
                res++;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}