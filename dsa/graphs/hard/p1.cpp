// catch the pawn
// https://www.hackerrank.com/contests/codantine/challenges/catch-the-pawn/problem

#include <bits/stdc++.h>
using namespace std;

bool catchPawn(int n, int ki, int kj, int pi, int pj)
{
    int di[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dj[8] = {1, 2, 2, 1, -1, -2, -2, -1}, m = 1;
    vector<vector<bool>> vis(n, vector<bool>(n));
    vector<vector<int>> dis(n, vector<int>(n));
    queue<pair<int, int>> q;
    vis[ki][kj] = true;
    q.push({ki, kj});
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            pair<int, int> from = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int i = from.first + di[dir], j = from.second + dj[dir];
                if (i >= 0 && i < n && j >= 0 && j < n && !vis[i][j])
                {
                    vis[i][j] = true;
                    dis[i][j] = m;
                    q.push({i, j});
                }
            }
        }
        m++;
    }
    for (int j = pj; j < n; j++)
        if (dis[pi][j] <= j - pj && abs(dis[pi][j] - (j - pj)) % 2 == 0)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, ki, kj, pi, pj;
        cin >> n >> ki >> kj >> pi >> pj;
        cout << catchPawn(n, ki, kj, pi, pj) << "\n";
    }
    return 0;
}
