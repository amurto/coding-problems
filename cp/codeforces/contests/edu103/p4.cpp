#include <bits/stdc++.h>
using namespace std;

const int N = 7e5;
int parent[N], cap[N];

void init(int n)
{
    for (int i = 0; i <= n; i++)
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

void merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if (rx == ry)
        return;
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
}

void solve()
{
    int n;
    string str;
    cin >> n >> str;
    init(2 * n + 1);
    for (int i = 0; i < n; i++)
        (str[i] == 'L') ? merge(i + n + 1, i + 1) : merge(i, i + n + 2);
    for (int i = 0; i <= n; i++)
        cout << cap[root(i)] << " ";
    cout << "\n";
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
