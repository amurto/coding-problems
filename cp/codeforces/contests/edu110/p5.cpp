#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 3e5 + 5, LGN = 19;
vector<int> g[N];
int up[N][LGN + 1], arr[N], cost[N];

void add(int id, int p, int a, int c)
{
    g[p].pb(id);
    arr[id] = a;
    cost[id] = c;
    up[id][0] = p;
    for (int i = 1; i <= LGN; i++)
        up[id][i] = up[up[id][i - 1]][i - 1];
}

int ancestor(int x)
{
    for (int i = LGN; i >= 0; i--)
        if (arr[up[x][i]] > 0)
            x = up[x][i];
    return x;
}

void solve()
{
    int q, t;
    for (int i = 0; i <= LGN; i++)
        up[0][i] = 0;
    cin >> q >> arr[0] >> cost[0];
    for (int i = 1; i <= q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            int p, a, c;
            cin >> p >> a >> c;
            add(i, p, a, c);
        }
        else
        {
            int v, w;
            cin >> v >> w;
            int tmp = w;
            ll sum = 0;
            while (w > 0 && arr[v] > 0)
            {
                int a = ancestor(v);
                int rem = min(w, arr[a]);
                sum += 1ll * rem * cost[a];
                w -= rem;
                arr[a] -= rem;
            }
            cout << tmp - w << " " << sum << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}