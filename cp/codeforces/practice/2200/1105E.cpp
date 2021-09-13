// https://codeforces.com/contest/1105/problem/E
// Helping Hiasat

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 40;
int g[N][N];

void dfs(vector<int> &dp, int mask, int cur, int f, int m)
{
    if (cur == m)
    {
        dp[mask] = __builtin_popcount(mask);
        return;
    }
    // set
    // check if any neighbour is set
    bool pos = true;
    for (int i = 0; pos && i < cur; i++)
        if (g[cur + f][i + f] && ((mask >> i) & 1))
            pos = false;
    if (pos)
        dfs(dp, mask | (1 << cur), cur + 1, f, m);
    // dont set
    dfs(dp, mask, cur + 1, f, m);
}

int solve()
{
    int n, m, res = 1;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            g[i][j] = 0;
    vector<int> op(n), ids(n);
    vector<string> arr(n), unq;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> op[i];
        if (op[i] == 2)
        {
            cin >> arr[i];
            unq.pb(arr[i]);
        };
    }
    if (m == 1)
        return res;
    sort(unq.begin(), unq.end());
    unq.resize(unique(unq.begin(), unq.end()) - unq.begin());
    for (int i = 0; i < m; i++)
        mp[unq[i]] = i;
    for (int i = 0; i < n; i++)
        if (op[i] == 2)
            ids[i] = mp[arr[i]];
    for (int i = 0; i < n;)
    {
        int r = i + 1;
        vector<bool> vis(m);
        vector<int> tmp_ids;
        while (r < n && op[r] == 2)
        {
            if (!vis[ids[r]])
            {
                vis[ids[r]] = true;
                tmp_ids.pb(ids[r]);
            }
            r++;
        }
        if (!tmp_ids.empty())
            for (int j = 0; j < tmp_ids.size(); j++)
                for (int k = 0; k < j; k++)
                    g[tmp_ids[j]][tmp_ids[k]] = g[tmp_ids[k]][tmp_ids[j]] = 1;
        i = r;
    }
    int h1 = m / 2;
    int h2 = m - h1;
    vector<int> dp1(1 << h1), dp2(1 << h2);
    dfs(dp1, 0, 0, 0, h1);
    dfs(dp2, 0, 0, h1, h2);
    for (int i = 0; i < h1; ++i)
        for (int mask = 0; mask < (1 << h1); ++mask)
            if (mask & (1 << i))
                dp1[mask] = max(dp1[mask], dp1[mask ^ (1 << i)]);
    for (int mask = 0; mask < (1 << h2); mask++)
    {
        if (dp2[mask] > 0)
        {
            int req = 0;
            for (int i = 0; i < h2; i++)
                if ((mask >> i) & 1)
                    for (int j = 0; j < h1; j++)
                        if (g[j][i + h1])
                            req |= (1 << j);
            req ^= ((1 << h1) - 1);
            res = max(res, dp1[req] + dp2[mask]);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}