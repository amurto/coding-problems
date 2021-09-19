#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<int> deg(n);
    vector<bool> vis(n);
    vector<vector<int>> arr(n), g(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++)
    {
        int k, v;
        cin >> k;
        deg[i] = k;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            v--;
            arr[i].pb(v);
            g[v].pb(i);
        }
        if (deg[i] == 0)
            pq.push({i, i});
    }
    if (pq.empty())
        return -1;
    ll t = pq.top().first;
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        vis[cur.second] = true;
        t = cur.first;
        for (int x : g[cur.second])
        {
            if (--deg[x] == 0)
            {
                ll dis = x - cur.second;
                if (dis < 0)
                    dis += n;
                pq.push({t + dis, x});
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (!vis[i])
            return -1;
    return (t + n) / n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}