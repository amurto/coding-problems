#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll p = n - 1;
    for (ll d = 2; d < n; d++)
    {
        p += 2 * (n / d) - 2;
        if (n % d == d - 1)
            p++;
    }
    cout << p << "\n";
    return 0;
}