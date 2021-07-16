// https://codeforces.com/contest/877/problem/D
// Olya and Energy Drinks

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int inf = 1e9 + 7;

int solve()
{
    int n, m, k, x1, y1, x2, y2;
    cin >> n >> m >> k;
    vector<string> grid(n);
    vector<vector<int>> dis(n, vector<int>(m, inf));
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    vector<set<int>> rows(n), cols(m);
    for (int i = 0; i < n; i++)
        for (int j = -1; j <= m; j++)
            rows[i].insert(j);
    for (int j = 0; j < m; j++)
        for (int i = -1; i <= n; i++)
            cols[j].insert(i);
    queue<pii> q;
    q.push({x1, y1});
    rows[x1].erase(y1);
    cols[y1].erase(x1);
    dis[x1][y1] = 0;
    int d = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            pii cur = q.front();
            int i = cur.first, j = cur.second;
            q.pop();
            vector<int> del;

            // up
            auto it = cols[j].lower_bound(i);
            it--;
            while (*it != -1 && abs(*it - i) <= k && grid[*it][j] == '.')
            {
                dis[*it][j] = d;
                del.pb(*it);
                q.push({*it, j});
                it--;
            }
            for (int r : del)
            {
                rows[r].erase(j);
                cols[j].erase(r);
            }
            del.clear();

            // down
            it = cols[j].lower_bound(i);
            while (*it != n && abs(*it - i) <= k && grid[*it][j] == '.')
            {
                dis[*it][j] = d;
                del.pb(*it);
                q.push({*it, j});
                it++;
            }
            for (int r : del)
            {
                rows[r].erase(j);
                cols[j].erase(r);
            }
            del.clear();

            // left
            it = rows[i].lower_bound(j);
            it--;
            while (*it != -1 && abs(*it - j) <= k && grid[i][*it] == '.')
            {
                dis[i][*it] = d;
                del.pb(*it);
                q.push({i, *it});
                it--;
            }
            for (int c : del)
            {
                rows[i].erase(c);
                cols[c].erase(i);
            }
            del.clear();

            // right
            it = rows[i].lower_bound(j);
            while (*it != m && abs(*it - j) <= k && grid[i][*it] == '.')
            {
                dis[i][*it] = d;
                del.pb(*it);
                q.push({i, *it});
                it++;
            }
            for (int c : del)
            {
                rows[i].erase(c);
                cols[c].erase(i);
            }
            del.clear();
        }
        d++;
    }
    return (dis[x2][y2] >= inf) ? -1 : dis[x2][y2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}