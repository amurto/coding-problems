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

int dfs(vector<vector<int>> &grid, int mask, int val, int sz)
{
    if (mask == ((1 << sz) - 1))
        return val;
    int res = 0;
    for (int i = 0; i < sz; i++)
    {
        if (!((mask >> i) & 1))
        {
            for (int j = i + 1; j < sz; j++)
                if (!((mask >> j) & 1))
                    res = max(res, dfs(grid, mask | (1 << i) | (1 << j), val ^ grid[i][j], sz));
            break;
        }
    }
    return res;
}
int solve()
{
    int n;
    cin >> n;
    int sz = 2 * n;
    vector<vector<int>> grid(sz, vector<int>(sz));
    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            cin >> grid[i][j];
            grid[j][i] = grid[i][j];
        }
    }
    return dfs(grid, 0, 0, sz);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}