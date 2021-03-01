#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int u, v;
    cin >> u >> v;
    if (u > v)
        return false;
    vector<int> ub, vb;
    for (int b = 0; b <= 30; b++)
    {
        if (u & (1 << b))
            ub.pb(b);
        if (v & (1 << b))
            vb.pb(b);
    }
    if (ub.size() < vb.size())
        return false;
    for (int i = 0; i < vb.size(); i++)
        if (ub[i] > vb[i])
            return false;
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