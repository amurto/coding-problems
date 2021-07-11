#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e18;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> pos(k);
    vector<ll> res(n + 1, inf), tmp(n + 1, inf);
    for (int i = 0; i < k; i++)
        cin >> pos[i];
    for (int i = 0; i < k; i++)
        cin >> tmp[pos[i]];
    ll mn = inf;
    for (int i = 1; i <= n; i++)
    {
        mn = min(mn + 1, tmp[i]);
        res[i] = min(res[i], mn);
    }
    mn = inf;
    for (int i = n; i > 0; i--)
    {
        mn = min(mn + 1, tmp[i]);
        res[i] = min(res[i], mn);
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