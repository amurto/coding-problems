// https://codeforces.com/contest/771/problem/A
// Bear and Friendship Condition

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 150005;
int parent[N], cap[N], edge[N];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        cap[i] = 1;
        edge[i] = 0;
    }
}

int root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

void dsunion(int x, int y)
{
    int rx = root(x), ry = root(y);
    if (rx == ry)
    {
        edge[rx]++;
        return;
    }
    // by size (capacity)
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    edge[rx] += edge[ry] + 1;
    parent[ry] = parent[rx];
}

ll nc2(int x)
{
    return x * 1ll * (x - 1) / 2;
}

bool solve()
{
    int n, m, u, v;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        dsunion(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        int r = root(i);
        if (edge[r] < nc2(cap[r]))
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}