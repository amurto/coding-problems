#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

struct edge
{
    int v, t, i, j;
    edge(int tv, int tt, int ti, int tj)
    {
        v = tv;
        t = tt;
        i = ti;
        j = tj;
    }
};

bool check_valid(vector<vector<int>> &grid, vector<string> &str, int m)
{
    vector<int> arr1, arr2;
    for (int i = 0; i < m; i++)
    {
        int t = 0;
        for (int j = 0; j < (int)grid[i].size(); j++)
        {
            if (str[i][j] == 'L')
            {
                arr1.pb(grid[i][j]);
                t++;
            }
            else
            {
                arr2.pb(grid[i][j]);
                t--;
            }
        }
        if (t != 0)
            return false;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    return arr1 == arr2;
}

void solve()
{
    int m;
    cin >> m;
    vector<vector<int>> grid(m);
    vector<string> str(m);
    vector<int> sz(m);
    vector<bool> vis(m);
    for (int i = 0; i < m; i++)
    {
        cin >> sz[i];
        grid[i].resize(sz[i]);
        str[i].resize(sz[i]);
        for (int j = 0; j < sz[i]; j++)
            cin >> grid[i][j];
        for (int j = 0; j < sz[i]; j++)
            str[i][j] = '0';
    }
    map<int, int> cnt;
    for (int i = 0; i < m; i++)
    {
        if (sz[i] & 1)
        {
            cout << "NO\n";
            return;
        }
        for (int x : grid[i])
            cnt[x]++;
    }
    for (auto x : cnt)
    {
        if (x.second & 1)
        {
            cout << "NO\n";
            return;
        }
    }
    vector<vector<edge>> g(m);
    map<int, vector<edge>> mp;
    vector<int> ptr_g(m);
    map<int, int> ptr_mp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < sz[i]; j++)
        {
            g[i].pb(edge(grid[i][j], 1, i, j));
            mp[grid[i][j]].pb(edge(i, 0, i, j));
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < sz[i]; j++)
        {
            if (str[i][j] == '0')
            {
                queue<pii> q;
                q.push({grid[i][j], 1});
                while (!q.empty())
                {
                    pii cur = q.front();
                    q.pop();
                    if (cur.second == 0)
                    {
                        vis[cur.first] = true;
                        int len = (int)g[cur.first].size();
                        while (ptr_g[cur.first] < len && str[g[cur.first][ptr_g[cur.first]].i][g[cur.first][ptr_g[cur.first]].j] != '0')
                            ptr_g[cur.first]++;
                        if (ptr_g[cur.first] < len)
                        {
                            edge e = g[cur.first][ptr_g[cur.first]];
                            str[e.i][e.j] = 'L';
                            q.push({e.v, e.t});
                            ptr_g[cur.first]++;
                        }
                    }
                    else
                    {
                        int len = (int)mp[cur.first].size();
                        while (ptr_mp[cur.first] < len && str[mp[cur.first][ptr_mp[cur.first]].i][mp[cur.first][ptr_mp[cur.first]].j] != '0')
                            ptr_mp[cur.first]++;
                        if (ptr_mp[cur.first] < len)
                        {
                            edge e = mp[cur.first][ptr_mp[cur.first]];
                            str[e.i][e.j] = 'R';
                            q.push({e.v, e.t});
                            ptr_mp[cur.first]++;
                        }
                    }
                }
            }
        }
    }
    cout << "YES\n";
    for (string s : str)
        cout << s << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}