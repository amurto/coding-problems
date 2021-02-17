#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e15;

ll solve()
{
    int n1, n2, n3, n4, m1, m2, m3, x, y;
    cin >> n1 >> n2 >> n3 >> n4;
    vector<pair<ll, ll>> a(n1), b(n2), c(n3), d(n4);
    ll res = inf;
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i].first;
        b[i].second = i + 1;
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> c[i].first;
        c[i].second = i + 1;
    }
    for (int i = 0; i < n4; i++)
    {
        cin >> d[i].first;
        d[i].second = i + 1;
    }
    vector<set<int>> ap(n1 + 1), bp(n2 + 1), cp(n3 + 1);
    cin >> m1;
    for (int i = 0; i < m1; i++)
    {
        cin >> x >> y;
        ap[x].insert(y);
    }
    cin >> m2;
    for (int i = 0; i < m2; i++)
    {
        cin >> x >> y;
        bp[x].insert(y);
    }
    cin >> m3;
    for (int i = 0; i < m3; i++)
    {
        cin >> x >> y;
        cp[x].insert(y);
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < n3; i++)
    {
        int j = 0;
        while (cp[i + 1].find(d[j].second) != cp[i + 1].end() && j < n4)
            j++;
        if (j == n4)
            c[i].first += inf;
        else
            c[i].first += d[j].first;
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n2; i++)
    {
        int j = 0;
        while (bp[i + 1].find(c[j].second) != bp[i + 1].end() && j < n3)
            j++;
        if (j == n3)
            b[i].first += inf;
        else
            b[i].first += c[j].first;
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n1; i++)
    {
        int j = 0;
        while (ap[i + 1].find(b[j].second) != ap[i + 1].end() && j < n2)
            j++;
        if (j == n2)
            a[i].first += inf;
        else
            a[i].first += b[j].first;
        res = min(res, a[i].first);
    }
    if (res >= inf)
        return -1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}