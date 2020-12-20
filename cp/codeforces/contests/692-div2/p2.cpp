#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool good(ll n)
{
    ll x = n;
    while (x > 0)
    {
        if (x % 10 > 0 && n % (x % 10) > 0)
            return false;
        x /= 10;
    }
    return true;
}

ll solve()
{
    ll n;
    cin >> n;
    while (!good(n))
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