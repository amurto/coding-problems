#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5e5 + 1, MOD = 1e9 + 7;
int parent[N], cap[N];

void init(int m)
{
    for (int i = 1; i <= m; i++)
    {
        parent[i] = i;
        cap[i] = 1;
    }
}

int root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

bool merge(int rx, int ry)
{
    rx = root(rx);
    ry = root(ry);
    if (rx == ry)
        return false;
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m;
    init(m + 1);
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        int e1 = m + 1, e2 = m + 1;
        cin >> e1;
        if (k > 1)
            cin >> e2;
        if (merge(e1, e2))
            res.pb(i + 1);
    }
    int sz = res.size(), ans = 1;
    for (int i = 0; i < sz; i++)
        ans = (ans * 1ll * 2) % MOD;
    cout << ans << " " << sz << "\n";
    for (int r : res)
        cout << r << " ";
    return 0;
}