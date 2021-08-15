#ifdef amurto
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
    int n;
    cin >> n;
    vector<ll> s(n), t(n), mn(n);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({t[i], i});
        mn[i] = t[i];
    }
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        if (!vis[cur.second])
        {
            vis[cur.second] = true;
            int nxt = (cur.second + 1) % n;
            if (cur.first + s[cur.second] < mn[nxt])
            {
                mn[nxt] = cur.first + s[cur.second];
                pq.push({mn[nxt], nxt});
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << mn[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}