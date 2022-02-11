// https://codeforces.com/contest/1200/problem/F
// Graph Traveler

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

const int MOD = 2520;

int add(int x, int y)
{
    x += y;
    x %= MOD;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

void solve()
{
    int n, q;
    cin >> n;
    vector<int> arr(n + 1), sz(n + 1);
    vector<vector<int>> g(n + 1), dp(n + 1, vector<int>(MOD)), vis(n + 1, vector<int>(MOD));
    vector<vector<pii>> last(n + 1, vector<pii>(MOD));
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] = add(arr[i], MOD);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> sz[i];
        g[i].resize(sz[i]);
        for (int j = 0; j < sz[i]; j++)
            cin >> g[i][j];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < MOD; j++)
        {
            if (vis[i][j] == 0)
            {
                int ans = -1;
                pii cur = {i, j}, last_cur = {-1, -1}, mn = {-1, -1};
                while (ans == -1)
                {
                    if (vis[cur.first][cur.second] == 2)
                    {
                        ans = dp[cur.first][cur.second];
                        cur = last_cur;
                        break;
                    }
                    vis[cur.first][cur.second]++;
                    if (vis[cur.first][cur.second] == 2)
                    {
                        set<int> st;
                        st.insert(cur.first);
                        pii tmp = last_cur;
                        while (tmp != cur)
                        {
                            st.insert(tmp.first);
                            tmp = last[tmp.first][tmp.second];
                        }
                        cur = last_cur;
                        ans = (int)st.size();
                        break;
                    }
                    last[cur.first][cur.second] = last_cur;
                    int tmp_j = add(cur.second, arr[cur.first]);
                    last_cur = cur;
                    cur = {g[cur.first][tmp_j % sz[cur.first]], tmp_j};
                }

                pii tmp = cur;
                while (tmp != mn)
                {
                    dp[tmp.first][tmp.second] = ans;
                    vis[tmp.first][tmp.second] = 2;
                    tmp = last[tmp.first][tmp.second];
                }
            }
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        y = add(y, 0);
        cout << dp[x][y] << "\n";
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