#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, m, g = 0;
    cin >> n >> m;
    ll res = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        g = __gcd(g, val);
    }
    d(g);
    if (g == 1)
    {
        for (ll x : arr)
            res += abs(x);
        return res;
    }
    vector<vector<int>> st(g);
    for (int i = 0; i < n; i++)
        st[i % g].pb(arr[i]);
    for (int i = 0; i < g; i++)
    {
        sort(st[i].begin(), st[i].end());
        int sz = (int)st[i].size();
        ll sum = 0;
        for (ll x : st[i])
            sum += x;
        ll mx = sum;
        for (int j = 1; j < sz; j += 2)
        {
            sum -= st[i][j - 1];
            sum -= st[i][j];
            st[i][j - 1] = -st[i][j - 1];
            st[i][j] = -st[i][j];
            sum += st[i][j - 1];
            sum += st[i][j];
            mx = max(mx, sum);
        }
        res += mx;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}