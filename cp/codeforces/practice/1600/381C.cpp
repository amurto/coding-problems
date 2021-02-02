// https://codeforces.com/contest/381/problem/C
// Sereja and Prefixes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
int tp[N], x[N], c[N];
ll sap(vector<ll> &pos, ll id)
{
    int i = (lower_bound(pos.begin(), pos.end(), id) - pos.begin());
    if (tp[i] == 1)
        return x[i];
    id -= pos[i - 1];
    id %= x[i];
    if (id == 0)
        id += x[i];
    return sap(pos, id);
}

void solve()
{
    int n, m;
    cin >> m;
    vector<ll> pos(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> tp[i] >> x[i];
        if (tp[i] > 1)
            cin >> c[i];
        pos[i] = (tp[i] == 1) ? pos[i - 1] + 1 : pos[i - 1] + (x[i] * 1ll * c[i]);
    }
    cin >> n;
    vector<ll> idx(n);
    for (int i = 0; i < n; i++)
    {
        cin >> idx[i];
        idx[i] = sap(pos, idx[i]);
    }
    for (ll e : idx)
        cout << e << " ";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}