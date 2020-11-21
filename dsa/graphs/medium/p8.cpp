// https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/grid-of-many-xors-de84b766/
// Grid of Many Xors

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m, r1, c1, r2, c2, cost = 0;
        int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
        cin >> n >> m >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        vector<vector<int>> grid(n, vector<int>(m));
        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        priority_queue<piii, vector<piii>, greater<piii>> pq;
        pq.push({0, {r1, c1}});
        while (!pq.empty())
        {
            piii from = pq.top();
            pq.pop();
            if (vis[from.second.first][from.second.second])
                continue;
            vis[from.second.first][from.second.second] = true;
            cost += from.first;
            for (int dir = 0; dir < 4; dir++)
            {
                int i = from.second.first + di[dir], j = from.second.second + dj[dir];
                if (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j])
                    pq.push({grid[from.second.first][from.second.second] ^ grid[i][j], {i, j}});
            }
        }
        cout << cost << "\n";
    }
    return 0;
}