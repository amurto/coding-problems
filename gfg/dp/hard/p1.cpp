// https://practice.geeksforgeeks.org/problems/minimum-cost-path/0
// Minimum Cost Path

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool valid(int i, int j, int n)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
        int n, i, j, x, y;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        queue<pair<int, int>> Q;
        dist[0][0] = grid[0][0];
        Q.push({0, 0});
        while (!Q.empty())
        {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for (int idx = 0; idx < 4; idx++)
            {
                i = x + dx[idx];
                j = y + dy[idx];
                if (valid(i, j, n) && (dist[x][y] + grid[i][j] < dist[i][j]))
                {
                    dist[i][j] = dist[x][y] + grid[i][j];
                    Q.push({i, j});
                }
            }
        }
        cout<<dist[n-1][n-1]<<endl;
    }
    return 0;
}