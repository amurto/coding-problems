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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m)), suf_mn(n, vector<int>(m)), suf_mx(n, vector<int>(m)), vis(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
        suf_mn[i][m - 1] = suf_mx[i][m - 1] = arr[i][m - 1];
    for (int j = m - 2; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            suf_mn[i][j] = min(arr[i][j], suf_mn[i][j + 1]);
            suf_mx[i][j] = max(arr[i][j], suf_mx[i][j + 1]);
        }
    }
    vector<int> pre_mn(n, 1e7), pre_mx(n);
    for (int c = 0; c < m - 1; c++)
    {
        // red -> 0
        // blue -> 1
        int mn1 = 1e7, mx1 = 0, mn2 = 1e7, mx2 = 0;
        for (int i = 0; i < n; i++)
        {
            vis[i][0] = vis[i][1] = 0;
            pre_mn[i] = min(pre_mn[i], arr[i][c]);
            pre_mx[i] = max(pre_mx[i], arr[i][c]);
            mn1 = min(mn1, pre_mn[i]);
            mx1 = max(mx1, pre_mx[i]);
            mn2 = min(mn2, suf_mn[i][c + 1]);
            mx2 = max(mx2, suf_mx[i][c + 1]);
        }
        // d(mn1,mn2,mx1,mx2);
        priority_queue<pii> pq_mx;
        priority_queue<pii, vector<pii>, greater<pii>> pq_mn;
        for (int i = 0; i < n; i++)
            pq_mx.push({pre_mx[i], i});
        while (!pq_mx.empty() && mx1 <= pq_mx.top().first)
        {
            pii cur = pq_mx.top();
            pq_mx.pop();
            vis[cur.second][0] = 1;
            mx1 = min(mx1, pre_mn[cur.second]);
        }
        while (!pq_mx.empty())
            pq_mx.pop();
        for (int i = 0; i < n; i++)
            pq_mx.push({suf_mx[i][c + 1], i});
        while (!pq_mx.empty() && mx2 <= pq_mx.top().first)
        {
            pii cur = pq_mx.top();
            pq_mx.pop();
            vis[cur.second][1] = 1;
            mx2 = min(mx2, suf_mn[cur.second][c + 1]);
        }
        for (int i = 0; i < n; i++)
            pq_mn.push({pre_mn[i], i});
        while (!pq_mn.empty() && mn1 >= pq_mn.top().first)
        {
            pii cur = pq_mn.top();
            pq_mn.pop();
            vis[cur.second][1] = 1;
            mn1 = max(mn1, pre_mx[cur.second]);
        }
        while (!pq_mn.empty())
            pq_mn.pop();
        for (int i = 0; i < n; i++)
            pq_mn.push({suf_mn[i][c + 1], i});
        while (!pq_mn.empty() && mn2 >= pq_mn.top().first)
        {
            pii cur = pq_mn.top();
            pq_mn.pop();
            vis[cur.second][0] = 1;
            mn2 = max(mn2, suf_mx[cur.second][c + 1]);
        }
        bool pos = true;
        for (int i = 0; pos && i < n; i++)
            if (vis[i][0] + vis[i][1] == 2)
                pos = false;
        if (pos)
        {
            vector<int> ids;
            for (int i = 0; i < n; i++)
                if (vis[i][0] + vis[i][1] == 0)
                    ids.pb(i);
            
            int l_mn = 1e7, l_mx = 0, r_mn = 1e7, r_mx = 0;
            for (int i = 0; i < n; i++)
            {
                if (vis[i][0] == 1)
                {
                    l_mn = min(l_mn, pre_mn[i]);
                    r_mx = max(r_mx, suf_mx[i][c + 1]);
                }
                else if (vis[i][1] == 1)
                {
                    l_mx = max(l_mx, pre_mx[i]);
                    r_mn = min(r_mn, suf_mn[i][c + 1]);
                }
            }
            if (l_mn > l_mx && r_mn > r_mx)
            {
                string res(n, 'R');
                for (int i = 0; i < n; i++)
                    if (vis[i][1] == 1)
                        res[i] = 'B';
                cout << "YES\n";
                cout << res << " " << c + 1 << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
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