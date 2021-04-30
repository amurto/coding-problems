#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> st(n + 1);
    vector<ll> u(n), s(n), res(n + 1);
    for (int i = 0; i < n; i++)
        cin >> u[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        st[u[i] - 1].pb(s[i]);
    for (int i = 0; i < n; i++)
    {
        if (st[i].empty())
            continue;
        int sz = st[i].size();
        sort(st[i].rbegin(), st[i].rend());
        vector<ll> pre(sz);
        pre[0] = st[i][0];
        for (int j = 1; j < sz; j++)
            pre[j] = pre[j - 1] + st[i][j];
        for (int k = 1; k <= sz; k++)
        {
            int rem = sz % k;
            res[k] += pre[sz - 1 - rem];
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << "\n";
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