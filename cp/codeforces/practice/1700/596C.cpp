// https://codeforces.com/contest/596/problem/C
// Wilbur and Points

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, x, y, w;
    cin >> n;
    vector<pii> res(n);
    map<int, vector<pii>> st;
    map<int, vector<int>> wt;
    map<pii, int> rnk;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        st[y - x].pb({x, y});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w;
        wt[w].pb(i);
    }
    for (auto x : wt)
    {
        int key = x.first;
        if (x.second.size() != st[key].size())
        {
            cout << "NO\n";
            return;
        }
        sort(st[key].begin(), st[key].end());
        for (int i = 0; i < x.second.size(); i++)
        {
            res[x.second[i]] = st[key][i];
            rnk[res[x.second[i]]] = x.second[i] + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        x = res[i].first;
        y = res[i].second;
        int r1 = rnk[{x + 1, y}], r2 = rnk[{x, y + 1}];
        if ((r1 > 0 && r1 < i + 1) || (r2 > 0 && r2 < i + 1))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (pii r : res)
        cout << r.first << " " << r.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}