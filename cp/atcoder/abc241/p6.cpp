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

ll get_hash(ll x, ll y)
{
    return (x << 30ll) + y;
}

ll solve()
{
    ll h, w, sx, sy, gx, gy;
    int n;
    cin >> h >> w >> n >> sx >> sy >> gx >> gy;
    vector<ll> X(n), Y(n);
    map<ll, vector<ll>> mpX, mpY;
    for (int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
        mpX[X[i]].pb(Y[i]);
        mpY[Y[i]].pb(X[i]);
    }
    for (auto &v : mpX)
        sort(v.second.begin(), v.second.end());
    for (auto &v : mpY)
        sort(v.second.begin(), v.second.end());
    set<ll> vis;
    queue<pii> q;
    q.push({sx, sy});
    vis.insert(get_hash(sx, sy));
    ll dis = 0;
    while (!q.empty())
    {
        int sz = (int)q.size();
        while (sz > 0)
        {
            pii cur = q.front();
            ll cx = cur.first, cy = cur.second;
            q.pop();
            if (cx == gx && cy == gy)
                return dis;
            if (!mpX[cx].empty())
            {
                int len = mpX[cx].size();
                int id = lower_bound(mpX[cx].begin(), mpX[cx].end(), cy) - mpX[cx].begin();
                if (id < len)
                {
                    ll tx = cx, ty = mpX[cx][id] - 1;
                    if (ty > cy && vis.find(get_hash(tx, ty)) == vis.end())
                    {
                        vis.insert(get_hash(tx, ty));
                        q.push({tx, ty});
                    }
                }
                if (id - 1 >= 0)
                {
                    ll tx = cx, ty = mpX[cx][id - 1] + 1;
                    if (ty < cy && vis.find(get_hash(tx, ty)) == vis.end())
                    {
                        vis.insert(get_hash(tx, ty));
                        q.push({tx, ty});
                    }
                }
            }
            if (!mpY[cy].empty())
            {
                int len = mpY[cy].size();
                int id = lower_bound(mpY[cy].begin(), mpY[cy].end(), cx) - mpY[cy].begin();
                if (id < len)
                {
                    ll tx = mpY[cy][id] - 1, ty = cy;
                    if (tx > cx && vis.find(get_hash(tx, ty)) == vis.end())
                    {
                        vis.insert(get_hash(tx, ty));
                        q.push({tx, ty});
                    }
                }
                if (id - 1 >= 0)
                {
                    ll tx = mpY[cy][id - 1] + 1, ty = cy;
                    if (tx < cx && vis.find(get_hash(tx, ty)) == vis.end())
                    {
                        vis.insert(get_hash(tx, ty));
                        q.push({tx, ty});
                    }
                }
            }
            sz--;
        }
        dis++;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}