#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 3e5 + 5, LGN = 19;
set<int> g[N];
int up[N][LGN + 1], arr[N], cost[N], dep[N], cur = 1;
vector<bool> del(N);

int add(int p, int a, int c)
{
    g[p].insert(++cur);
    up[cur][0] = p;
    for (int i = 1; i <= LGN; i++)
        up[cur][i] = up[up[cur][i - 1]][i - 1];
    dep[cur] = dep[p] + 1;
}

ll remove(int v, int w)
{
}

void solve()
{

    int q, t;
    cin >> q >> arr[1] >> cost[1];
    g[0].insert(1);
    dep[0] = 0;
    dep[1] = 1;
    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            int p, a, c;
            cin >> p >> a >> c;
            add(p, a, c);
        }
        else
        {
            int v, w;
            cin >> v >> w;
            cout << rem(v, w) << "\n";
            fflush(stdout);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}