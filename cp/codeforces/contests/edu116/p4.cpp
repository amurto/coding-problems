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
        int mn = 1e7, mx = 0;
        for (int i = 0; i < n; i++)
        {
            vis[i][0] = vis[i][1] = 0;
            pre_mn[i] = min(pre_mn[i], arr[i][c]);
            pre_mx[i] = max(pre_mx[i], arr[i][c]);
            mx = max(mx, pre_mx[i]);
            mn = min(mn, suf_mn[i][c + 1]);
        }
        priority_queue<pii> pq_mx;
        priority_queue<pii, vector<pii>, greater<pii>> pq_mn;
        for (int i = 0; i < n; i++)
            pq_mx.push({pre_mx[i], i});
        for (int i = 0; i < n; i++)
            pq_mn.push({suf_mn[i][c + 1], i});
        while (!pq_mn.empty() && !pq_mx.empty())
        {
            while (!pq_mn.empty() && mn >= pq_mn.top().first)
            {
                pii cur = pq_mn.top();
                pq_mn.pop();
                vis[cur.second][0] = 1;
                mx = min(mx, pre_mn[cur.second]);
                mn = max(mn, suf_mx[cur.second][c + 1]);
            }
            while (!pq_mx.empty() && mx <= pq_mx.top().first)
            {
                pii cur = pq_mx.top();
                pq_mx.pop();
                vis[cur.second][0] = 1;
                mx = min(mx, pre_mn[cur.second]);
                mn = max(mn, suf_mx[cur.second][c + 1]);
            }
            if (!pq_mn.empty() && !pq_mx.empty() && mn < pq_mn.top().first && mx > pq_mx.top().first)
                break;
        }
        if (!pq_mn.empty() && !pq_mx.empty())
        {
            string res(n, 'B');
            for (int i = 0; i < n; i++)
                if (vis[i][0] == 1)
                    res[i] = 'R';
            cout << "YES\n";
            cout << res << " " << c + 1 << "\n";
            return;
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