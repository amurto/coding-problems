// https://www.spoj.com/problems/CHAIN/
// Strange Food Chain
// dsu

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MAX = 50001;
int parent[MAX], type[MAX];

int root(int x)
{
    if (x == parent[x])
        return x;
    int father = parent[x];
    parent[x] = root(parent[x]);
    type[x] += type[father];
    return parent[father];
}

bool dsunion(int q, int x, int y, int n)
{
    if (x > n || y > n)
        return true;
    int rx = root(x), ry = root(y);
    int diff = ((type[x] - type[y] - q) % 3 + 3) % 3;
    if (rx == ry)
        return diff != 0;
    parent[rx] = ry;
    type[rx] = 3 - diff;
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
        int n, k, q, x, y, wrong = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            type[i] = 0;
        }
        for (int i = 0; i < k; i++)
        {
            cin >> q >> x >> y;
            wrong+=dsunion(q-1, x, y, n);
        }
        cout << wrong << "\n";
    }
    return 0;
}