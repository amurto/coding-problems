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
    int n;
    cin >> n;
    vector<ll> L(n), R(n), C(n);
    for (int i = 0; i < n; i++)
        cin >> L[i] >> R[i] >> C[i];
    ll l = L[0], r = R[0], l_cost = C[0], r_cost = C[0], tot = C[0];
    cout << C[0] << "\n";
    for (int i = 1; i < n; i++)
    {
        ll old_l = l, old_r = r;
        l = min(l, L[i]);
        r = max(r, R[i]);
        if (old_l == l && old_r == r)
        {
            if (L[i] == l && R[i] == r)
                tot = min(tot, C[i]);
            if (L[i] == l)
                l_cost = min(l_cost, C[i]);
            if (R[i] == r)
                r_cost = min(r_cost, C[i]);
        }
        else
        {
            tot = inf;
            if (L[i] == l && R[i] == r)
                tot = min(tot, C[i]);
            if (old_l != l)
                l_cost = inf;
            if (old_r != r)
                r_cost = inf;
            if (L[i] == l)
                l_cost = min(l_cost, C[i]);
            if (R[i] == r)
                r_cost = min(r_cost, C[i]);
        }
        cout << min(l_cost + r_cost, tot) << "\n";
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