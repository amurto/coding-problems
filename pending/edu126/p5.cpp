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

void solve()
{
    int n, q, t = 0, di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
    cin >> n;
    vector<string> str(3);
    for (int i = 0; i < 3; i++)
        cin >> str[i];
    vector<vector<int>> grid(3, vector<int>(n)), num(3, vector<int>(n, -1));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++)
            grid[i][j] = str[i][j] - '0';
    // Lambda recursive function
    auto dfs = [&](const auto &self, int i, int j) -> void
    {
        num[i][j] = t;
        for (int dir = 0; dir < 4; dir++)
        {
            int ti = i + di[dir], tj = j + dj[dir];
            if (ti >= 0 && ti < 3 && tj >= 0 && tj < n && grid[ti][tj] == 1 && num[ti][tj] == -1)
                self(self, ti, tj);
        }
    };
    vector<int> comps;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (num[i][j] == -1)
            {
                dfs(dfs, i, j);
                t++;
                comps.pb(j);
            }
        }
    }
    vector<vector<int>> pillars(t);
    for (int j = 0; j < n; j++)
        if (grid[0][j] + grid[1][j] + grid[2][j] == 3)
            pillars[num[0][j]].pb(j);
    sort(comps.begin(), comps.end());
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r, res = 0;
        cin >> l >> r;
        l--;
        r--;
        if (l == r)
        {
            int sum = grid[0][l] + grid[1][l] + grid[2][l];
            if (sum == 3)
                res = 1;
            else if (sum == 2)
            {
                if (grid[0][l] + grid[2][l] == 2)
                    res = 2;
                else
                    res = 1;
            }
            else
                res = sum;
        }
        else
        {
            int id1 = lower_bound(comps.begin(), comps.end(), l) - comps.begin();
            int id2 = upper_bound(comps.begin(), comps.end(), r + 1) - comps.begin();
            int cnt = id2 - id1;
            if (cnt > 0)
            {
                int v1 = 0, v2 = 0;
                if (grid[0][l] + grid[2][l] == 2 && num[0][l] == num[2][l])
                {
                    int c_num = num[0][l];
                    int id = lower_bound(pillars[c_num].begin(), pillars[c_num].end(), l) - pillars[c_num].begin();
                    if (id >= (int)pillars[c_num].size() || pillars[c_num][id] > r)
                        v1++;
                }
                if (grid[0][r] + grid[2][r] == 2 && num[0][r] == num[2][r])
                {
                    int c_num = num[0][r];
                    int id = upper_bound(pillars[c_num].begin(), pillars[c_num].end(), r + 1) - pillars[c_num].begin();
                    id--;
                    if (id < 0 || pillars[c_num][id] < l)
                        v2++;
                }
                cnt += v1;
                cnt += v2;
                // if (v1 + v2 == 2)
                // {
                //     if (num[0][l] == num[0][r])
                // }
                res = cnt;
            }
        }

        cout << res << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}