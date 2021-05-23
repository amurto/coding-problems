#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll g, res = 0;
    cin >> g;
    g *= 2;
    for (ll i = 1; i * i <= g; i++)
    {
        if (g % i == 0 && g / i > i)
        {
            ll d = g / i - i + 1;
            res += (d % 2 == 0);
        }
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
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}