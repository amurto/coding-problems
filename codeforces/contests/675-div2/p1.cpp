#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = floor(sqrt(((a + b) * (a + b)) + c * c)) - 1;
        cout << ans << "\n";
    }
    return 0;
}