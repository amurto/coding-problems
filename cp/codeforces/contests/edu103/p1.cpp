#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n, k;
    cin >> n >> k;
    if (k < n)
    {
        k = k * (n / k);
        while (k < n)
            k += k;
    }
    ll res = k / n + (k % n > 0);
    return res;
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