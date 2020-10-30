# Graphs

## Structure
```cpp
```

## Table of Contents
- [Number of Islands](#number-of-islands)
- [Friend Circles](#friend-circles)
- [Rotting Oranges](#rotting-oranges)
- [Is Graph Bipartite?][#is-graph-bipartite]

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

<div id="rotting-oranges">

## Rotting Oranges
https://leetcode.com/problems/rotting-oranges/
```cpp
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
```
</div>

<div id="is-graph-bipartite">

## Is Graph Bipartite?
https://leetcode.com/problems/is-graph-bipartite/
```cpp
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> vis(n);
    vector<int> parity(n);
    queue<int> Q;
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            int level = 0;
            Q.push(i);
            while (!Q.empty())
            {
                level ^= 1;
                int nodes = Q.size();
                while (nodes-- > 0)
                {
                    int cur = Q.front();
                    Q.pop();
                    if (!vis[cur])
                    {
                        vis[cur] = true;
                        parity[cur] = level;
                        for (int edge : graph[cur])
                            if (!vis[edge])
                                Q.push(edge);
                    }
                    else if (parity[cur] != level)
                        return false;
                }
            }
        }
    return true;
}
```
</div>