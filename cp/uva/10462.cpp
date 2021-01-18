// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1403
// 10462 - Is There A Second Way Left?

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

const int N = 101;
int parent[N], cap[N];
vector<int> mark;
void init(int n)
{
    for (int i = 1; i <= n; i++)
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

bool merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if (rx == ry)
        return false;

    // by size (capacity)
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    return true;
}

int mst(vector<piii> &e, int n, int m, int idx, bool st)
{
    int cost = 0;
    init(n);
    for (int j = 0; j < m; j++)
    {
        if (j == idx)
            continue;
        if (merge(e[j].second.first, e[j].second.second))
        {
            if (st)
                mark.pb(j);
            cost += e[j].first;
        }
    }
    for (int j = 1; j <= n; j++)
        if (cap[j] == n)
            return cost;
    return -1;
}
void solve(int tc)
{
    mark.clear();
    int n, m;
    cin >> n >> m;
    cout << "Case #" << tc << " : ";
    vector<int> c;
    vector<piii> e(m);
    for (int i = 0; i < m; i++)
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
    if (n == 1)
    {
        cout << "No second way\n";
        return;
    }
    sort(e.begin(), e.end());
    int res = mst(e, n, m, -1, true);
    if (res == -1)
    {
        cout << "No way\n";
        return;
    }
    for (int edge : mark)
    {
        int cur = mst(e, n, m, edge, false);
        if (cur >= 0)
            c.pb(cur);
    }
    sort(c.begin(), c.end());
    if (c.empty())
        cout << "No second way\n";
    else
        cout << c[0] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve(tc);
    return 0;
}