#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

const ll d = 1e5;
void solve()
{
    int n, m;
    cin >> n, m;
    vector<ll> t(n), y(n);
    vector<pii> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> x[i].first >> y[i];
        if (t[i] == 1)
            x[i].first = (x[i].first + d - 1) / d;
        else
        {
            ll g = __gcd(x[i].first, d);
            x[i].first /= g;
            x[i].second = d / g;
        }
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