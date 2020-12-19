#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w, m, r, c, i, inf = 1e6;
    cin >> h >> w >> m;
    vector<int> row(h + 1, h + 1), col(w + 1, w + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> r >> c;
        row[r] = min(row[r], c);
        col[c] = min(col[c], r);
    }
    ll vis = 1;
    for (i = 2; i <= min(h, w); i++)
    {
        ll rvis = 0, cvis = 0;
        rvis = min(row[i], i) - 1;
        cvis = min(col[i], i) - 1;
        if (i < row[i] || i < col[i])
            vis++;
        vis += rvis + cvis;
    }
    while (i<=h) {
        vis += row[i]- 1;
        i++;
    }

    return 0;
}