// Number of Islands
// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

// use the given grid to store visited cells
// convert land to water after visiting them
// O(n*m) time and space
int numIslands(vector<vector<char>> &grid)
{
    int islands = 0, n = grid.size(), m = grid[0].size(), di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '1')
            {
                islands++;
                stack<pair<int, int>> st;
                st.push({i, j});
                grid[i][j] = '0';
                while (!st.empty())
                {
                    pair<int, int> top = st.top();
                    st.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int x = top.first + di[dir], y = top.second + dj[dir];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1')
                        {
                            grid[x][y] = '0';
                            st.push({x, y});
                        }
                    }
                }
            }
    return islands;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << numIslands(grid) << "\n";
    return 0;
}