// https://codeforces.com/contest/1198/problem/C
// Matching vs Independent Set

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<bool> vis(3 * n + 1);
    vector<pii> edges(m);
    vector<int> matching, ind_set;
    for (int i = 0; i < m; i++)
        cin >> edges[i].first >> edges[i].second;
    for (int i = 0; i < m; i++)
    {
        pii e = edges[i];
        if (!vis[e.first] && !vis[e.second])
        {
            matching.pb(i + 1);
            vis[e.first] = true;
            vis[e.second] = true;
        }
    }
    for (int i = 1; i <= 3 * n; i++)
        if (!vis[i])
            ind_set.pb(i);
    if (matching.size() < n && ind_set.size() < n)
    {
        cout << "Impossible\n";
        return;
    }
    if (matching.size() >= n)
    {
        cout << "Matching\n";
        for (int i = 0; i < n; i++)
            cout << matching[i] << " ";
        cout << "\n";
    }
    else
    {
        cout << "IndSet\n";
        for (int i = 0; i < n; i++)
            cout << ind_set[i] << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}