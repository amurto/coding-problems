// https://www.spoj.com/problems/CHAIN/
// Strange Food Chain
// dsu

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MAX = 50001;
pii parent[MAX][3];
int RANK[MAX][3];

pii root(pii x)
{
    if (parent[x.first][x.second] == x)
        return x;
    return parent[x.first][x.second] = root(parent[x.first][x.second]);
}

bool same(pii x, pii y) {
    return (root(x) == root(y));
}

void merge(pii x, pii y)
{
    pii rx = root(x), ry = root(y);
    if (rx == ry)
        return;
    if (RANK[rx.first][rx.second] < RANK[ry.first][ry.second])
        swap(rx, ry);
    parent[ry.first][ry.second] = parent[rx.first][rx.second];
    RANK[rx.first][rx.second] += RANK[ry.first][ry.second];
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
        int n, k, kind, x, y, wrong = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            RANK[i][0] = RANK[i][1] = RANK[i][2] = 0;
            parent[i][0] = {i, 0};
            parent[i][1] = {i, 1};
            parent[i][2] = {i, 2};
        }
        for (int i = 0; i < k; i++)
        {
            cin >> kind >> x >> y;
            if (x == y || x > n || y > n)
            {
                wrong++;
                continue;
            }
            pii x0 = {x, 0}, x1 = {x, 1}, x2 = {x, 2}, y0 = {y, 0}, y1 = {y, 1}, y2 = {y, 2};
            if (kind == 1)
            {
                if (same(x0, y1) || same(x0,y2) || same(x1, y0) || same(x1, y2) || same(x2, y0) || same(x2, y1)) {
                    wrong++;
                    continue;
                }
                merge(x0, y0);
                merge(x1, y1);
                merge(x2, y2);
            }
            else
            {
                if (same(x0, y1) || same(x1, y2) || same(x2, y0)) {
                    wrong++;
                    continue;
                }
            }   
        }
        cout << wrong << "\n";
    }
    return 0;
}