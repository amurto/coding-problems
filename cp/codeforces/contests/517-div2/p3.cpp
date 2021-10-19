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

ll ap(ll n)
{
    return (n * (2 + n - 1)) / 2;
}
void solve()
{
    ll a, b, res = 0;
    cin >> a >> b;
    if (a + b == 0)
    {
        for (int i = 0; i < 2; i++)
            cout << "0\n\n";
        return;
    }
    ll sum = a + b, low = 1, high = 1e5;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll small = min(a, b), tot = ap(mid);
        if (tot > sum)
            high = mid - 1;
        else
        {
            ll rem = small, cur = mid;
            while (rem > 0 && tot > 0)
            {
                tot -= min(rem, cur);
                rem -= min(rem, cur);
                cur--;
            }
            if (tot <= max(a, b))
            {
                res = max(res, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    vector<ll> arr1, arr2, vis(res + 1);
    ll tot = ap(res), rem = min(a, b), cur = res;
    if (a < b)
    {
        while (rem > 0 && tot > 0)
        {
            vis[min(rem, cur)] = true;
            tot -= min(rem, cur);
            rem -= min(rem, cur);
            cur--;
        }
        for (ll i = 1; i <= res; i++)
            if (vis[i])
                arr1.pb(i);
            else
                arr2.pb(i);
    }
    else
    {
        while (rem > 0 && tot > 0)
        {
            vis[min(rem, cur)] = true;
            tot -= min(rem, cur);
            rem -= min(rem, cur);
            cur--;
        }
        for (ll i = 1; i <= res; i++)
            if (vis[i])
                arr2.pb(i);
            else
                arr1.pb(i);
    }
    cout << (int)arr1.size() << "\n";
    for (ll x : arr1)
        cout << x << " ";
    cout << "\n";
    cout << (int)arr2.size() << "\n";
    for (ll x : arr2)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}