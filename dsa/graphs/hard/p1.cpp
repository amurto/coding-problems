// catch the pawn
// tbd

#include <bits/stdc++.h>
using namespace std;

bool catchPawn(int n, int ki, int kj, int pi, int pj)
{
    int di[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dj[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    pj++;
    queue<pair<int, int>> q;
    q.push({ki, kj});

    while (pj < n)
    {
        int size = q.size();
        vector<vector<bool>> vis(n, vector<bool>(n));
        while (size-- > 0)
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int i = cur.first + di[dir], j = cur.second + dj[dir];
                if (i >= 0 && i < n && j >= 0 && j < n && abs(pj - j) <= abs(pj - cur.second) && !vis[i][j])
                {
                    if (i == pi && j>=pj)
                        return true;
                    vis[i][j] = true;
                    q.push({i, j});
                }
            }
        }
        pj++;
    }
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
