#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

ll solve()
{
    ll n, a, b, x, y, z, res = LLONG_MAX;
    cin >> n >> a >> b >> x >> y >> z;
    vector<pii> seq;
    seq.pb({x, 1ll});
    seq.pb({y, a});
    seq.pb({z, b});
    seq.pb({x + y, 1ll + a});
    seq.pb({y + z, a + b});
    seq.pb({x + z, 1ll + b});
    seq.pb({x + y + z, 1ll + a + b});
    vector<int> ids{0, 1, 2, 3, 4, 5, 6};
    do
    {
        ll v = n, cost = 0;
        for (int i = 0; v > 0 && i < 7; i++)
        {
            int id = ids[i];
            ll req = v / seq[id].second;
            v -= (req * seq[id].second);
            cost += (req * seq[id].first);
        }
        res = min(res, cost);
    } while (next_permutation(ids.begin(), ids.end()));
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