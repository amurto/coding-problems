// https://codeforces.com/contest/441/problem/D
// Valera and Swaps

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

void dfs(vector<int> &arr, vector<bool> &vis, vector<int> &c, int cur)
{
    vis[cur] = true;
    c.pb(cur);
    if (!vis[arr[cur]])
        dfs(arr, vis, c, arr[cur]);
}

void solve()
{
    int n, m, op = 0;
    cin >> n;
    vector<int> arr(n + 1), pos(n + 1);
    vector<bool> vis(n + 1);
    vector<pii> ops;
    vector<int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> c;
            dfs(arr, vis, c, i);
            st.pb(i);
            op += (int)c.size() - 1;
        }
    }
    cin >> m;
    if (op < m)
    {
        for (int i = 1; op < m; i++, op++)
            ops.pb({1, st[i]});
    }
    else if (op > m)
    {
        for (int i = 1; op > m && i <= n; i++)
        {
            while (op > m && arr[i] != i)
            {
                int cur = arr[i], mn = arr[i];
                while (cur != i)
                {
                    mn = min(mn, cur);
                    cur = arr[cur];
                }
                ops.pb({i, mn});
                swap(pos[arr[i]], pos[arr[mn]]);
                swap(arr[i], arr[mn]);
                op--;
            }
        }
    }
    cout << ops.size() << "\n";
    for (pii p : ops)
        cout << p.first << " " << p.second << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}