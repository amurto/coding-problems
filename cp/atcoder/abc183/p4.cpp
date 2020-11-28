#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, w, s, t, p;
    cin >> n >> w;
    vector<pair<int, int>> d;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t >> p;
        d.pb({s, p});
        d.pb({t, -p});
    }
    sort(d.begin(), d.end());
    ll cur = 0;
    for (pair<int, int> e : d)
    {
        cur += e.second;
        if (cur > w)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (solve())
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}