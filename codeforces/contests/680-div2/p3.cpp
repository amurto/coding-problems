#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve(ll p, ll q) {
    if (p%q!=0)
        return p;
    ll cq = q;
    vector<ll> factors;
    // prime factorisation
    for (ll i=2; i*i <= cq; i++) {
        if (cq%i == 0) {
            factors.pb(i);
            while (cq%i==0)
                cq/=i;
        }
    }

    // extra step to add largest prime factor
    if (cq > 1)
        factors.pb(cq);
        
    ll x = 0;
    for (ll fac: factors) {
        ll cp = p;
        while (cp%q==0)
            cp/=fac;
        x = max(x, cp);
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    while (t-- > 0)
    {
        ll p, q;
        cin >> p >> q;
        cout << solve(p, q) << "\n";
    }
    return 0;
}