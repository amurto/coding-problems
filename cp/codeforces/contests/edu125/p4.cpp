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

const ll inf = 1e18;
void solve()
{
    int n, m, tot;
    cin >> n >> tot;
    vector<ll> arr(tot + 1), cost(tot + 1);
    for (int i = 0; i < n; i++)
    {
        ll c, dmg, h;
        cin >> c >> dmg >> h;
        arr[c] = max(arr[c], dmg * h);
    }
    cin >> m;
    vector<ll> dmgM(m), hM(m), req(m, -1);
    for (int i = 0; i < m; i++)
        cin >> dmgM[i] >> hM[i];
    for (int i = 1; i <= tot; i++)
        if (arr[i] > 0)
            for (int j = i, t = 1; j <= tot; j += i, t++)
                cost[j] = max(cost[j], arr[i] * t);
    for (int i = 2; i <= tot; i++)
        cost[i] = max(cost[i - 1], cost[i]);
    for (int i = 0; i < m; i++)
    {
        ll val = dmgM[i] * hM[i];
        if (cost[tot] > val)
        {
            int id = upper_bound(cost.begin(), cost.end(), val) - cost.begin();
            req[i] = id;
        }
    }
    for (ll x : req)
        cout << x << " ";
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