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

bool solve()
{
    int n, m, k, c;
    cin >> n >> m;
    vector<vector<int>> pos(n + 1, vector<int>(2, -1));
    vector<queue<int>> st(m);
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c;
            if (pos[c][0] == -1)
                pos[c][0] = i;
            else
                pos[c][1] = i;
            st[i].push(c);
        }
    }
    int rem = 0;
    queue<int> q;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (pos[i][0] == pos[i][1])
            return false;
        if (st[pos[i][0]].front() == i && st[pos[i][1]].front() == i)
        {
            vis[i] = true;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        rem++;
        int l = pos[cur][0], r = pos[cur][1];
        st[l].pop();
        st[r].pop();
        if (!st[l].empty())
        {
            int t = st[l].front();
            if (!vis[t] && st[pos[t][0]].front() == t && st[pos[t][1]].front() == t)
            {
                vis[t] = true;
                q.push(t);
            }
        }
        if (!st[r].empty())
        {
            int t = st[r].front();
            if (!vis[t] && st[pos[t][0]].front() == t && st[pos[t][1]].front() == t)
            {
                vis[t] = true;
                q.push(t);
            }
        }
    }
    return rem == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}