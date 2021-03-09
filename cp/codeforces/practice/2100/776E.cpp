// https://codeforces.com/contest/776/problem/E
// The Holmes Children

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

ll solve()
{
    ll n, k;
    cin >> n >> k;
    k = (k + 1) / 2;
    while (n > 1 && k-- > 0)
        n = phi(n);
    n %= MOD;
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}