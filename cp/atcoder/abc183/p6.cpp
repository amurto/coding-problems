#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 1;
int c[N], parent[N], cap[N];
map<int, int> cnt[N];

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
    for (auto c : cnt[ry])
        cnt[rx][c.first] += c.second;
    cap[rx] += cap[ry];
    parent[ry] = parent[rx];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, c;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        parent[i] = i;
        cap[i] = 1;
        cnt[i][c] = 1;
    }
    while (q-- > 0)
    {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
            merge(x, y);
        else
            cout << cnt[root(x)][y] << "\n";
    }
    return 0;
}