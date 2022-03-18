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

int query(int u, int v)
{
    cout << "? 3 1 " << u << " " << v << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> anc(n + 1);
    vector<pii> edges;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            if (i != j && query(i, j))
                anc[j].pb(i);
    vector<int> seq, dep(n + 1);
    for (int i = 2; i <= n; i++)
    {
        seq.pb(i);
        dep[i] = (int)anc[i].size() + 1;
    }
    sort(seq.begin(), seq.end(), [&](int i1, int i2)
         { return dep[i1] < dep[i2]; });
    for (int node : seq)
    {
        if (anc[node].empty())
            edges.pb({1, node});
        else
        {
            for (int e : anc[node])
                if (dep[e] == dep[node] - 1)
                    edges.pb({e, node});
        }
    }
    cout << "!" << endl;
    for (pii e : edges)
        cout << e.first << " " << e.second << endl;
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