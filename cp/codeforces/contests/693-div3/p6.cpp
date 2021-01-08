#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(m);
    for (int i = 0; i < m; i++)
        cin >> p[i].second >> p[i].first;
    sort(p.begin(), p.end());
    vector<int> mask;
    mask.pb(p[0].second);
    for (int i = 1; i < m; i++)
    {
        if (p[i].first == p[i - 1].first)
            mask[mask.size() - 1] = 3;
        else
        {
            int par = p[i].first - (p[i - 1].first + 1);
            par %= 2;
            if (par)
                mask.pb(0);
            mask.pb(p[i].second);
        }
    }
    for (int i = 0; i < mask.size(); i++)
    {
        if (mask[i] == 0 || mask[i] == 3)
            continue;
        if (i == mask.size() - 1)
            return false;
        int req = 3 - mask[i];
        if (mask[i + 1] & req)
            return false;
        mask[i + 1] |= req;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}