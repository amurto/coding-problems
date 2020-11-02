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
    ll fac = 1;
    for (int i = 1; i < n; i++)
        fac = i * fac;
    ll ans = 2 * fac / n;
    cout << ans << "\n";
    return 0;
}