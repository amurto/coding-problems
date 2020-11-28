#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n;
        cin >> n;
        ll sq = floor(sqrt(n));
        ll ans = sq - 1 + n / sq;
        if (n % sq == 0)
            ans--;
        cout << ans << endl;
    }
    return 0;
}