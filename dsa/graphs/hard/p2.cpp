// https://www.codechef.com/problems/FIRESC/
// Fire Escape Routes
// dsu

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;
void init(vector<int> &parent, int n)
{
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int root(vector<int> &parent, int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent, parent[x]);
}

void dsunion(vector<int> &parent, vector<int> &size, int x, int y)
{
    int rx = root(parent, x), ry = root(parent, y);
    if (rx == ry)
        return;
    if (size[rx] < size[ry])
        swap(rx, ry);
    size[rx] += size[ry];
    parent[ry] = parent[rx];
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
        int n, m, x, y;
        cin >> n >> m;
        vector<int> parent(n + 1), size(n + 1, 1);
        init(parent, n);
        while (m-- > 0)
        {
            cin >> x >> y;
            dsunion(parent, size, x, y);
        }
        int routes = 0, ways = 1;
        for (int i = 1; i <= n; i++)
        {
            if (parent[i] != i)
                continue;
            routes++;
            ways = (ways * 1ll * size[i]) % MOD;
        }
        cout << routes << " " << ways << "\n";
    }
    return 0;
}