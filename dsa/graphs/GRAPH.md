# Graphs

## Structure
```cpp
```

## Table of Contents
- [Number of Islands](#number-of-islands)
- [Friend Circles](#friend-circles)

<div id="number-of-islands">

## Number of Islands
https://leetcode.com/problems/number-of-islands/
```cpp
// DFS using stack
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
```
</div>

<div id="friend-circles">

## Friend Circles
https://leetcode.com/problems/friend-circles/
```cpp
// DFS using stack
// O(n*m) time and space
int findCircleNum(vector<vector<int>> &M)
{
    int circles = 0, n = M.size(), m = M[0].size();
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            circles++;
            stack<int> st;
            st.push(i);
            vis[i] = true;
            while (!st.empty())
            {
                int cur = st.top();
                st.pop();
                for (int j = 0; j < m; j++)
                    if (!vis[j] && M[cur][j] == 1)
                    {
                        st.push(j);
                        vis[j] = true;
                    }
            }
        }
    return circles;
}
```
</div>