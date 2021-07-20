#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i;
    ll ans = fac[n];
    ans /= fac[n / 2];
    ans /= fac[n / 2];
    ans /= 2;
    ans *= fac[n / 2 - 1];
    ans *= fac[n / 2 - 1];
    cout << ans << "\n";
    return 0;
}