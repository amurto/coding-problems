// https://codeforces.com/contest/1146/problem/D
// Frog Jumping

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

ll nc2(ll n)
{
    return (n * (n + 1)) / 2;
}

ll solve()
{
    int m, a, b;
    cin >> m >> a >> b;
    ll res = m + 1;
    int n = min(m, 2 * max(a, b) + 5), g = __gcd(a, b);
    vector<int> dis(n + 1, n + 5);
    vector<bool> vis(n + 1);
    auto cmp = [](pii &p1, pii &p2)
    {
        if (p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
    };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

    pq.push({0, 0});
    dis[0] = 0;
    while (!pq.empty())
    {
        pii cur = pq.top();
        pq.pop();
        if (!vis[cur.first])
        {
            vis[cur.first] = true;
            if (cur.first - b > 0 && max(dis[cur.first], cur.first - b) < dis[cur.first - b])
            {
                dis[cur.first - b] = max(dis[cur.first], cur.first - b);
                pq.push({cur.first - b, dis[cur.first - b]});
            }
            if (cur.first + a <= n && max(dis[cur.first], cur.first + a) < dis[cur.first + a])
            {
                dis[cur.first + a] = max(dis[cur.first], cur.first + a);
                pq.push({cur.first + a, dis[cur.first + a]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (vis[i])
            res += 1ll * (m - dis[i] + 1);
    if (m > n)
    {
        int rem = m- g * (n / g);
        int e = rem / g;
        res += 1ll * rem * e;
        res += 1ll * e;
        res -= 1ll * g * nc2(e);
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