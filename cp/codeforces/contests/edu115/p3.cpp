#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll nc2(ll n)
{
    return (n * (n - 1)) / 2;
}

ll solve()
{
    ll n, res = 0;
    cin >> n;
    ll m = n - 2;
    ll sum = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum == 0)
        return nc2(n);
    if ((((sum % n) * m) % n) != 0)
        return 0;
    ll g = __gcd(sum, n);
    ll s1 = sum / g, n1 = n / g;
    ll n_sum = (s1 * m) / n1;
    ll req = sum - n_sum;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= req)
            res += mp[req - arr[i]];
        mp[arr[i]]++;
    }
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