// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1994
// 11053 - Flavius Josephus Reloaded

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll ax2b(ll a, ll x, ll b)
{
    return a * x * x + b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, a, b;
    while (cin >> n >> a >> b)
    {
        unordered_map<ll, ll> MAP;
        ll i = 0, cnt = n;
        while (true)
        {
            MAP[i]++;
            ll v = MAP[i];
            if (v == 3)
                break;
            if (v == 2)
                cnt--;
            i = (a * (i * i % n) % n + b) % n;
        }
        cout << cnt << "\n";
    }
    return 0;
}