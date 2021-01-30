#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n, res = 0;
    cin >> n;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res += i % 2;
            if (i != n / i)
                res += ((n / i) % 2);
        }
    }
    return res * 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}