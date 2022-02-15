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
typedef pair<pair<int, int>, int> piii;
#define pb push_back

int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<piii> ops;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    vector<vector<int>> box = grid;
    queue<pii> q;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            set<int> st;
            if (i >= 0 && i < n && j >= 0 && j < m && box[i][j] != 0)
                st.insert(box[i][j]);
            if (i >= 0 && i < n && j >= 0 && j < m && box[i][j + 1] != 0)
                st.insert(box[i][j + 1]);
            if (i >= 0 && i < n && j >= 0 && j < m && box[i + 1][j] != 0)
                st.insert(box[i + 1][j]);
            if (i >= 0 && i < n && j >= 0 && j < m && box[i + 1][j + 1] != 0)
                st.insert(box[i + 1][j + 1]);
            if (!st.empty() && (int)st.size() == 1)
            {
                vis[i][j] = true;
                q.push({i, j});
                ops.pb({{i, j}, *st.begin()});
            }
        }
    }
    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();
        int r = cur.first, c = cur.second;

        box[r][c] = 0;
        box[r][c + 1] = 0;
        box[r + 1][c] = 0;
        box[r + 1][c + 1] = 0;

        for (int dir = 0; dir < 8; dir++)
        {
            int i = di[dir] + r, j = dj[dir] + c;
            if (i >= 0 && i < n - 1 && j >= 0 && j < m - 1 && !vis[i][j])
            {
                set<int> st;
                if (i >= 0 && i < n && j >= 0 && j < m && box[i][j] != 0)
                    st.insert(box[i][j]);
                if (i >= 0 && i < n && j >= 0 && j < m && box[i][j + 1] != 0)
                    st.insert(box[i][j + 1]);
                if (i >= 0 && i < n && j >= 0 && j < m && box[i + 1][j] != 0)
                    st.insert(box[i + 1][j]);
                if (i >= 0 && i < n && j >= 0 && j < m && box[i + 1][j + 1] != 0)
                    st.insert(box[i + 1][j + 1]);
                if (!st.empty() && (int)st.size() == 1)
                {
                    vis[i][j] = true;
                    q.push({i, j});
                    ops.pb({{i, j}, *st.begin()});
                }
            }
        }
    }
    vector<vector<int>> tmp(n, vector<int>(m));
    reverse(ops.begin(), ops.end());
    for (piii op : ops)
    {
        int i = op.first.first, j = op.first.second, col = op.second;
        tmp[i][j] = col;
        tmp[i][j + 1] = col;
        tmp[i + 1][j] = col;
        tmp[i + 1][j + 1] = col;
    }
    if (grid != tmp)
    {
        cout << "-1\n";
        return;
    }
    cout << (int)ops.size() << "\n";
    for (piii op : ops)
        cout << op.first.first + 1 << " " << op.first.second + 1 << " " << op.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}