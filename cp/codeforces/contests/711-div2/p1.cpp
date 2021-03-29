#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll g(ll n)
{
    ll x = n, sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return __gcd(n, sum);
}

ll solve()
{
    ll n;
    cin >> n;
    while (g(n) == 1)
        n++;
    return n;
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