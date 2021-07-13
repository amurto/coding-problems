// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/the-grass-type/
// The Grass Type

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
vector<int> g[N];
int arr[N], sz[N], ones[N], vis1[N], vis2[N], ver[N];
map<int, int> mp;

int set_sz(int cur, int last, int t)
{
    ones[cur] = (arr[cur] == 1);
    vis1[cur] = vis2[cur] = t;
    ver[t] = cur;
    sz[cur] = 1;
    for (int e : g[cur])
    {
        if (e != last)
        {
            vis2[cur] = max(vis2[cur], set_sz(e, cur, vis2[cur] + 1));
            sz[cur] += sz[e];
            ones[cur] += ones[e];
        }
    }
    return vis2[cur];
}

ll sack(int cur, int last, bool keep)
{
    ll res = 0;
    int mx = -1, big = -1;
    for (int e : g[cur])
        if (e != last && sz[e] > mx)
            mx = sz[e], big = e;
    for (int e : g[cur])
        if (e != last && e != big)
            res += sack(e, cur, false);
    if (big != -1)
        res += sack(big, cur, true) + 1ll * ones[big];
    mp[arr[cur]]++;
    for (int e : g[cur])
    {
        if (e != last && e != big)
        {
            for (int i = vis1[e]; i <= vis2[e]; i++)
                if (arr[cur] % arr[ver[i]] == 0)
                    res += 1ll * mp[arr[cur] / arr[ver[i]]];
            for (int i = vis1[e]; i <= vis2[e]; i++)
                mp[arr[ver[i]]]++;
        }
    }
    if (!keep)
        for (int i = vis1[cur]; i <= vis2[cur]; i++)
            mp[arr[ver[i]]]--;
    return res;
}

ll solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    set_sz(1, 1, 0);
    return sack(1, 1, true);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}