// https://codeforces.com/contest/25/problem/D
// Roads not only in Berland

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

bool dsunion(vector<int> &parent, vector<int> &size, int x, int y)
{
    int rx = root(parent, x), ry = root(parent, y);
    if (rx == ry)
        return false;
    if (size[ry] < size[ry])
        swap(rx, ry);
    size[rx] += size[ry];
    parent[ry] = parent[rx];
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, y, days = 0;
    cin >> n;
    vector<int> parent(n + 1), size(n + 1, 1);
    queue<pair<int, int>> unused;
    init(parent, n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        if (!dsunion(parent, size, x, y))
            unused.push({x, y});
    }
    int beg = 1;
    while (parent[beg] != beg)
        beg++;
    vector<pair<int, int>> roads;
    for (int i = beg + 1; i <= n; i++)
    {
        if (parent[i] != i)
            continue;
        days++;
        roads.push_back(unused.front());
        roads.push_back({beg, i});
        unused.pop();
    }
    cout << days << "\n";
    for (int i = 0; i < roads.size(); i += 2)
        cout << roads[i].first << " " << roads[i].second << " " << roads[i + 1].first << " " << roads[i + 1].second << "\n";
    return 0;
}