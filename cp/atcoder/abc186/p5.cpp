#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n, s, k;
    cin >> n >> s >> k;
    if (s % __gcd(n, k) > 0)
        return -1;
    ll req = -s;
    while (req<0) 
        req+=n;
    while (req%k >0) 
        req+=n;
    return req/k;
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