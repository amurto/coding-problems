#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 1e5 + 5;
int parent1[N], cap1[N], parent2[N], cap2[N];
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent1[i] = i;
        cap1[i] = 1;
        parent2[i] = i;
        cap2[i] = 1;
    }
}

int root1(int x)
{
    if (x == parent1[x])
        return x;
    return parent1[x] = root1(parent1[x]);
}

int root2(int x)
{
    if (x == parent2[x])
        return x;
    return parent2[x] = root2(parent2[x]);
}

void merge1(int x, int y)
{
    int rx = root1(x), ry = root1(y);
    if (rx == ry)
        return;
    // by size (cap1acity)
    if (cap1[rx] < cap1[ry])
        swap(rx, ry);
    cap1[rx] += cap1[ry];
    parent1[ry] = parent1[rx];
}

void merge2(int x, int y)
{
    int rx = root2(x), ry = root2(y);
    if (rx == ry)
        return;
    // by size (cap1acity)
    if (cap2[rx] < cap2[ry])
        swap(rx, ry);
    cap2[rx] += cap2[ry];
    parent2[ry] = parent2[rx];
}

void solve()
{
    int n, m1, m2, u, v;
    cin >> n >> m1 >> m2;
    init(n);
    for (int i = 0; i < m1; i++)
    {
        cin >> u >> v;
        merge1(u, v);
    }
    for (int i = 0; i < m2; i++)
    {
        cin >> u >> v;
        merge2(u, v);
    }
    vector<pii> edges;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int ri1 = root1(i), rj1 = root1(j), ri2 = root2(i), rj2 = root2(j);
            if (ri1 != rj1 && ri2 != rj2)
            {
                edges.pb({i, j});
                merge1(i, j);
                merge2(i, j);
            }
        }
    }
    cout << edges.size() << "\n";
    for (pii e : edges)
        cout << e.first << " " << e.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}