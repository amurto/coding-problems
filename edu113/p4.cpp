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

ll solve()
{
    int n, m, k, u, v;
    cin >> n >> m >> k;
    ll res = 0;
    // x_roads -> vertical roads
    // y_roads -> horizontal roads
    vector<int> x_roads, y_roads;
    set<int> x_st, y_st;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        x_roads.pb(v);
        x_st.insert(v);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> v;
        y_roads.pb(v);
        y_st.insert(v);
    }
    // pts_x -> point is on vertical road
    // pts_y -> point is on horizontal road
    vector<pii> pts_x, pts_y;
    for (int i = 0; i < k; i++)
    {
        cin >> u >> v;
        if (x_st.count(u) && y_st.count(v))
            continue;
        if (x_st.count(u))
            pts_x.pb({u, v});
        else
            pts_y.pb({u, v});
    }
    sort(pts_x.begin(), pts_x.end(), [&](pii &p1, pii &p2)
         {
             if (p1.second == p2.second)
                 return p1.first < p2.first;
             return p1.second < p2.second;
         });
    sort(pts_y.begin(), pts_y.end());
    int sz_x = (int)pts_x.size(), sz_y = (int)pts_y.size();
    if (sz_x > 0)
    {
        int cur = 0;
        for (int i = 1; i < m; i++)
        {
            // go through pts_x
            // goes through vertical roads
            int j = cur, cnt = 0;
            map<int, int> mp;
            while (cur < sz_x && pts_x[cur].second < y_roads[i])
            {
                mp[pts_x[cur].first]++;
                cur++;
                cnt++;
            }
            while (j < cur)
            {
                res += (1ll * (cnt - mp[pts_x[j].first]));
                j++;
            }
        }
    }
    if (sz_y > 0)
    {
        int cur = 0;
        for (int i = 1; i < n; i++)
        {
            // go through pts_y
            int j = cur, cnt = 0;
            map<int, int> mp;
            while (cur < sz_y && pts_y[cur].first < x_roads[i])
            {
                mp[pts_y[cur].second]++;
                cur++;
                cnt++;
            }
            while (j < cur)
            {
                res += (1ll * (cnt - mp[pts_y[j].second]));
                j++;
            }
        }
    }
    return res / 2;
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