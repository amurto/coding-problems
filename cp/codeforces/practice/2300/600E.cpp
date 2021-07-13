// https://codeforces.com/contest/600/problem/E
// Lomsat gelral

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
vector<int> g[N];
int arr[N], cnt[N], sz[N], vis1[N], vis2[N], ver[N], occ = 0;
ll fin[N], sum = 0;

int set_sz(int cur, int last, int t)
{
    vis1[cur] = vis2[cur] = t;
    ver[t] = cur;
    sz[cur] = 1;
    for (int e : g[cur])
    {
        if (e != last)
        {
            vis2[cur] = max(vis2[cur], set_sz(e, cur, vis2[cur] + 1));
            sz[cur] += sz[e];
        }
    }
    return vis2[cur];
}

void sack(int cur, int last, bool keep)
{
    int mx = -1, big = -1;
    for (int e : g[cur])
        if (e != last && sz[e] > mx)
            mx = sz[e], big = e;
    for (int e : g[cur])
        if (e != last && e != big)
            sack(e, cur, false);
    if (big != -1)
        sack(big, cur, true);
    cnt[arr[cur]]++;
    if (cnt[arr[cur]] > occ)
    {
        occ = cnt[arr[cur]];
        sum = arr[cur];
    }
    else if (cnt[arr[cur]] == occ)
        sum += 1ll * arr[cur];
    for (int e : g[cur])
    {
        if (e != last && e != big)
        {
            for (int i = vis1[e]; i <= vis2[e]; i++)
            {
                cnt[arr[ver[i]]]++;
                if (cnt[arr[ver[i]]] > occ)
                {
                    occ = cnt[arr[ver[i]]];
                    sum = arr[ver[i]];
                }
                else if (cnt[arr[ver[i]]] == occ)
                    sum += 1ll * arr[ver[i]];
            }
        }
    }
    fin[cur] = sum;
    if (!keep)
    {
        for (int i = vis1[cur]; i <= vis2[cur]; i++)
            cnt[arr[ver[i]]]--;
        occ = sum = 0;
    }
}

void solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        cnt[i] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    set_sz(1, 1, 0);
    sack(1, 1, true);
    for (int i = 1; i <= n; i++)
        cout << fin[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}