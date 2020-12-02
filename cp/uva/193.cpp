// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=129
// 193 - Graph Coloring

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int MAX = 0;
vector<int> res;

void gc(vector<vector<int>> &g, vector<int> &c, int cur, int cnt, int n)
{
    if (cur > n)
    {
        if (cnt > MAX)
        {
            MAX = cnt;
            res.clear();
            for (int i = 1; i <= n; i++)
                if (c[i] == 1)
                    res.pb(i);
        }
        return;
    }
    bool b = false;
    for (int edge : g[cur])
        if (c[edge] == 1)
        {
            b = true;
            break;
        }
    if (!b)
    {
        c[cur] = 1;
        gc(g, c, cur + 1, cnt + 1, n);
        c[cur] = 0;
    }
    gc(g, c, cur + 1, cnt, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        MAX = 0;
        res.clear();
        int n, k, u, v;
        cin >> n >> k;
        vector<vector<int>> g(n + 1);
        vector<int> c(n + 1);
        for (int i = 0; i < k; i++)
        {
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        gc(g, c, 1, 0, n);
        cout << res.size() << "\n";
        for (int i = 0; i < res.size() - 1; i++)
            cout << res[i] << " ";
        cout << res[res.size() - 1] << "\n";
    }
    return 0;
}