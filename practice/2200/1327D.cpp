// https://codeforces.com/contest/1327/problem/D
// Infinite Path

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> divs[N];

void init()
{
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divs[j].pb(i);
}

void dfs(vector<int> &p, vector<int> &comp, vector<bool> &vis, int cur)
{
    vis[cur] = true;
    comp.pb(cur);
    if (!vis[p[cur]])
        dfs(p, comp, vis, p[cur]);
}

int solve()
{
    int n, res = N;
    cin >> n;
    vector<int> p(n + 1), c(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vector<int> comp;
            dfs(p, comp, vis, i);
            int sz = (int)comp.size();
            for (int dv : divs[sz])
            {
                for (int j = 0; j < dv; j++)
                {
                    int col = c[comp[j]];
                    bool pos = true;
                    for (int k = j; pos && k < sz; k += dv)
                        if (c[comp[k]] != col)
                            pos = false;
                    if (pos)
                        res = min(res, dv);
                }
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}