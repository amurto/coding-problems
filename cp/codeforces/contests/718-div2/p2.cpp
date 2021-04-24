#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m)), g(n, vector<int>(m, -1)), run(n, vector<int>(m));
    vector<pair<int, int>> edge;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
            edge.pb({i, j});
        }
    }
    sort(edge.begin(), edge.end(), [&](pair<int, int> &p1, pair<int, int> &p2) {
        return b[p1.first][p1.second] < b[p2.first][p2.second];
    });
    for (int i = 0; i < m; i++)
        g[edge[i].first][edge[i].second] = i;
    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int i = 0; i < m; i++)
            st.insert(i);
        for (int j = 0; j < m; j++)
            if (g[i][j] >= 0)
                st.erase(g[i][j]);
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == -1)
            {
                g[i][j] = *st.begin();
                st.erase(st.begin());
            }
        }
        for (int j = 0; j < m; j++)
            run[i][g[i][j]] = b[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << run[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}