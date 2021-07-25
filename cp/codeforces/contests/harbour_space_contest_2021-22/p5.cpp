#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int add(int x, int y, int MOD)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int dfs(vector<int> &p, vector<int> &pos, vector<bool> &vis, int cur)
{
    vis[cur] = true;
    int nxt = pos[p[cur]];
    if (!vis[nxt])
        dfs(p, pos, vis, nxt);
    return 1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), f(n), pos(n), res;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i]--;
        f[add(i, -arr[i], n)]++;
        pos[arr[i]] = i;
    }
    int req = n - 2 * m;
    for (int j = 0; j < n; j++)
    {
        if (f[j] >= req)
        {
            vector<int> p(n);
            for (int i = 0; i < n; i++)
                p[i] = add(i, -j, n);
            vector<bool> vis(n);
            int c = n;
            for (int i = 0; i < n; i++)
                if (!vis[i])
                    c -= dfs(p, pos, vis, i);
            if (c <= m)
                res.pb(j);
        }
    }
    cout << res.size() << " ";
    for (int r : res)
        cout << r << " ";
    cout << "\n";
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