// https://www.spoj.com/problems/BITMAP/
// BITMAP - Bitmap

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
    cin >> t;
    while (t-- > 0)
    {
        int n, m, inf = 1000;
        cin >> n >> m;
        vector<vector<char>> bitmap(n, vector<char>(m));
        vector<vector<int>> dis(n, vector<int>(m, inf));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> bitmap[i][j];
                if (bitmap[i][j] == '1')
                {
                    q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }
        int d = 1;
        while (!q.empty())
        {
            int len = q.size();
            while (len-- > 0)
            {
                int r = q.front().first, c = q.front().second;
                q.pop();
                for (int dir = 0; dir <4; dir++) {
                    int i= r+di[dir], j = c+dj[dir];
                    if (i>=0 && i<n && j>=0 && j<m && bitmap[i][j] == '0') {
                        q.push({i, j});
                        bitmap[i][j] = '1';
                        dis[i][j] = d;
                    }
                }
            }
            d++;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++)
                cout << dis[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}