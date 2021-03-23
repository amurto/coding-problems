#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> piii;
#define pb push_back

const int N = 1e3 + 5;
int parent[N], cap[N];
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
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    return true;
}

int solve()
{
    int n, x, cost = 0;
    cin >> n;
    init(2 * n + 1);
    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
    for (int i = 0; i < 2 * n; i++)
        cin >> x;
    vector<piii> edge;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == -1)
                edge.pb({B[i][j], {i + 1, j + n + 1}});
    sort(edge.rbegin(), edge.rend());
    for (piii e : edge)
        if (!merge(e.second.first, e.second.second))
            cost += e.first;
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}