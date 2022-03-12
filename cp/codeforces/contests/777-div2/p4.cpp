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

vector<ll> get_factors(ll x)
{
    vector<ll> arr;
    for (ll i = 2; i * i <= x; i++)
    {
        while (x % i == 0)
        {
            arr.pb(i);
            x /= i;
        }
    }
    if (x > 1)
        arr.pb(x);
    return arr;
}

bool solve()
{
    ll x, dd, pw = 0;
    cin >> x >> dd;
    while ((x % dd) == 0)
    {
        x /= dd;
        pw++;
    }
    if (pw == 1)
        return false;
    vector<ll> arr = get_factors(x), nums = get_factors(dd);
    int sz = (int)arr.size(), dsz = (int)nums.size();
    if (sz > 1)
        return true;
    if (dsz == 1 || pw == 2)
        return false;
    if (sz == 1)
    {
        if (pw > 3)
            return true;
        else
        {
            bool pos = false;
            for (ll v : nums)
                if ((v * arr[0]) != dd)
                    pos = true;
            return pos;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}