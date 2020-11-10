// https://acm.timus.ru/problem.aspx?space=1&num=1003
// Parity
// dsu

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

map<pii, pii> parent;
map<pii, int> RANK;

pii root(pii x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

void merge(pii x, pii y)
{
    pii rx = root(x), ry = root(y);
    if (rx == ry)
        return;
    if (RANK[rx] < RANK[ry])
        swap(rx, ry);
    RANK[rx] += RANK[ry];
    parent[ry] = parent[rx];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n=0;
    while (n>=0)
    {
        cin >> n;
        if (n==-1)
            break;
        int q;
        string ans;
        cin >> q;
        vector<pii> edge(q);
        vector<int> parity(q);
        for (int i = 0; i < q; i++)
        {
            cin >> edge[i].first >> edge[i].second;
            cin >> ans;
            if (ans == "odd")
                parity[i] = 1;

            pii x0 = {edge[i].first - 1, 0}, x1 = {edge[i].first - 1, 1}, y0 = {edge[i].second, 0}, y1 = {edge[i].second, 1};
            parent[x0] = x0;
            parent[x1] = x1;
            parent[y0] = y0;
            parent[y1] = y1;
            RANK[x0] = RANK[x1] = RANK[y0] = RANK[y1] = 1;
        }
        int cur;
        for (cur = 0; cur < q; cur++)
        {
            pii x0 = {edge[cur].first - 1, 0}, x1 = {edge[cur].first - 1, 1}, y0 = {edge[cur].second, 0}, y1 = {edge[cur].second, 1};
            if (parity[cur] == 0)
            {
                merge(x0, y0);
                merge(x1, y1);
            }
            else
            {
                merge(x0, y1);
                merge(x1, y0);
            }
            if (root(x0) == root(x1) || root(y0) == root(y1))
                break;
        }
        cout << cur << "\n";
    }

    return 0;
}