# Graphs

## Structure
```cpp
```

## Table of Contents
- [Number of Islands](#number-of-islands)
- [Friend Circles](#friend-circles)
- [Rotting Oranges](#rotting-oranges)
- [Is Graph Bipartite?](#is-graph-bipartite)
- [Network Delay Time](#network-delay-time)
- [Steps by Knight](#steps-by-knight)

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

<div id="network-delay-time">

## Network Delay Time
https://leetcode.com/problems/network-delay-time/
```cpp
int networkDelayTime(vector<vector<int>> &times, int N, int K)
{
    // create a graph
    vector<vector<pair<int, int>>> g(N + 1);

    // adjacency list
    // g[u] = [[v,w]]
    for (vector<int> data : times)
        g[data[0]].push_back({data[1], data[2]});

    // dijkstra
    const int inf = 1e9;
    vector<int> dis(N + 1, inf);
    vector<bool> vis(N + 1);
    dis[K] = 0;

    // min heap
    // {dis[v], v}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[K], K});
    while (!pq.empty())
    {
        pair<int, int> from = pq.top();
        pq.pop();
        if (vis[from.second])
            continue;
        vis[from.second] = true;
        for (pair<int, int> to : g[from.second])
        {
            if (!vis[to.first])
            {
                if (dis[from.second] + to.second < dis[to.first])
                    dis[to.first] = dis[from.second] + to.second;
                pq.push({dis[to.first], to.first});
            }
        }
    }

    // return the farthest distance
    int time = 0;
    for (int i = 1; i <= N; i++)
        time = max(time, dis[i]);

    // farthest distance == inf then node cannot be reached
    return time == inf ? -1 : time;
}
```
</div>

<div id="steps-by-knight">

## Steps by Knight
https://practice.geeksforgeeks.org/problems/steps-by-knight/0
```cpp
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
```
</div>