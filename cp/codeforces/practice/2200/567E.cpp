// https://codeforces.com/contest/567/problem/E
// President and Roads

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

const ll inf = 1e15;

// adjacency list
// g[u] = [[v,w]]
vector<ll> dijkstra(vector<vector<pii>> &g, int n, int source)
{
    vector<ll> dis(n + 1, inf);
    vector<bool> vis(n + 1);
    dis[source] = 0;

    // min heap
    // {dis[v], v}
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dis[source], source});

    while (!pq.empty())
    {
        pii from = pq.top();
        pq.pop();
        if (!vis[from.second])
        {
            vis[from.second] = true;
            for (pii to : g[from.second])
            {
                if (!vis[to.first])
                {
                    if (dis[from.second] + to.second < dis[to.first])
                        dis[to.first] = dis[from.second] + to.second;
                    pq.push({dis[to.first], to.first});
                }
            }
        }
    }
    return dis;
}

void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<int> A(m), B(m);
    vector<ll> W(m), L(m), R(m);
    vector<bool> imp(m);
    vector<vector<pii>> g(n + 1), gt(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> A[i] >> B[i] >> W[i];
        g[A[i]].pb({B[i], W[i]});
        gt[B[i]].pb({A[i], W[i]});
    }
    vector<vector<ll>> dis(2);
    dis[0] = dijkstra(g, n, s);
    dis[1] = dijkstra(gt, n, t);
    ll mn = dis[0][t];
    vector<int> ids;
    for (int i = 0; i < m; i++)
    {
        if (dis[0][A[i]] + W[i] + dis[1][B[i]] == mn)
        {
            ids.pb(i);
            L[i] = dis[0][A[i]] + 1;
            R[i] = dis[0][A[i]] + W[i];
        }
    }
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         {
             if (L[i1] == L[i2])
                 return R[i1] < R[i2];
             return L[i1] < L[i2];
         });
    int sz = (int)ids.size();
    for (int i = 0; i < sz;)
    {
        int r = i;
        ll mx = R[ids[i]];
        while (r < sz && L[ids[r]] <= mx)
        {
            mx = max(mx, R[ids[r]]);
            r++;
        }
        if (i + 1 == r)
            imp[ids[i]] = true;
        i = r;
    }
    for (int i = 0; i < m; i++)
    {
        if (imp[i])
            cout << "YES\n";
        else
        {
            ll req = dis[0][A[i]] + W[i] + dis[1][B[i]] - mn + 1;
            if (req < W[i])
                cout << "CAN " << req << "\n";
            else
                cout << "NO\n";
        }
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