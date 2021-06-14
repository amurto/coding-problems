#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2005;
vector<int> g[N];
void query(int cur, int n)
{
    cout << "? " << cur << endl;
    int d;
    for (int i = 1; i <= n; i++)
    {
        cin >> d;
        if (d == -1)
            exit(0);
        if (d == 1)
            g[cur].pb(i);
    }
}

void solve()
{
    int n, d;
    cin >> n;
    vector<int> dep(n + 1);
    vector<vector<int>> nodes(2);
    cout << "? " << 1 << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> dep[i];
        if (dep[i] == 0)
            nodes[0].pb(i);
        else
            nodes[dep[i] % 2].pb(i);
    }
    int p = 0;
    if (nodes[0].size() > nodes[1].size())
        p = 1;
    for (int u : nodes[p])
    {
        if (u == 1)
        {
            for (int i = 2; i <= n; i++)
                if (dep[i] == 1)
                    g[1].pb(i);
        }
        else
            query(u, n);
    }
    cout << "! " << endl;
    for (int i = 1; i <= n; i++)
        for (int e : g[i])
            cout << i << " " << e << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}