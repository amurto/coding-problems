// https://codeforces.com/contest/1131/problem/D
// Gourmet choice

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 1005;
vector<int> g[N][2];
vector<pii> seq;

void assign_ids(vector<string> grid, int p)
{
    int sz = grid.size();
    vector<int> ids(sz);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return grid[i1] < grid[i2]; });
    if (p == 1)
        reverse(ids.begin(), ids.end());
    for (int i = 0, cur = 1; i < sz; cur++)
    {
        int r = i + 1;
        while (r < sz && grid[ids[i]] == grid[ids[r]])
            r++;
        for (int j = i; j < r; j++)
            g[cur][p].pb(ids[j]);
        seq.pb({p, cur});
        i = r;
    }
}

bool is_equal(vector<string> &grid, pii p1, pii p2)
{
    if (p1.first == p2.first)
        return false;
    if (p1.first > p2.first)
        swap(p1, p2);
    return grid[g[p1.second][0].back()][g[p2.second][1].back()] == '=';
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n), tmp;
    vector<vector<int>> res(2, vector<int>(max(n, m)));
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    assign_ids(grid, 0);
    for (int j = 0; j < m; j++)
    {
        string str = "";
        for (int i = 0; i < n; i++)
            str.pb(grid[i][j]);
        tmp.pb(str);
    }
    assign_ids(tmp, 1);
    sort(seq.begin(), seq.end(), [&](pii &p1, pii &p2)
         {
             if (p1.first == p2.first)
                 return p1.second < p2.second;
             if (p1.first == 0)
                 return grid[g[p1.second][0].back()][g[p2.second][1].back()] != '>';
             return grid[g[p2.second][0].back()][g[p1.second][1].back()] == '>';
         });
    int sz = seq.size();
    for (int i = 0, cur = 1; i < sz; cur++)
    {
        int r = i + 1;
        while (r < sz && is_equal(grid, seq[i], seq[r]))
            r++;
        for (int j = i; j < r; j++)
            for (int e : g[seq[j].second][seq[j].first])
                res[seq[j].first][e] = cur;
        i = r;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch = grid[i][j];
            int id1 = res[0][i], id2 = res[1][j];
            if (ch == '<' && id1 >= id2)
            {
                cout << "No\n";
                return;
            }
            if (ch == '=' && id1 != id2)
            {
                cout << "No\n";
                return;
            }
            if (ch == '>' && id1 <= id2)
            {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        cout << res[0][i] << " ";
    cout << "\n";
    for (int j = 0; j < m; j++)
        cout << res[1][j] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}