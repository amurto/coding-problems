#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

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

bool merge(vector<int> &parent, vector<int> &cap, int x, int y)
{
    int rx = root(parent, x), ry = root(parent, y);
    if (rx == ry)
        return true;

    // by size (capacity)
    if (cap[rx] < cap[ry])
        swap(rx, ry);
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
    return false;
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
        vector<int> row(n + 1), col(n + 1), parent(n + 1), cap(n + 1, 1);
        init(parent, n);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            row[y] = x;
            col[x] = y;
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (row[i] == 0 || row[i] == i)
                continue;
            if (col[i] == 0)
            {
                res++;
                continue;
            }
            if (merge(parent, cap, i, col[i]))
                res += 2;
            else
                res++;
        }
        cout << res << "\n";
    }
    return 0;
}