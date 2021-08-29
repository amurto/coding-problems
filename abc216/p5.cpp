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

ll ap(ll a, ll n)
{
    // sum = n/2*(2*a + (n-1)*d)
    return (n * (a * 2 + n - 1)) / 2;
}

ll solve()
{
    int n;
    ll k, res = 0;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    ll cur = 0;
    for (int i = 0; k > 0 && i < n; i++)
    {
        ll nxt = 0;
        if (i < n - 1)
            nxt = arr[i + 1];
        cur++;
        if ((cur * (arr[i] - nxt)) > k)
        {
            ll dv = k / cur;
            k %= cur;
            res += (cur * ap(arr[i] - dv + 1, dv));
            arr[i] -= dv;
            if (k > 0)
                res += (k * arr[i]);
            k = 0;
        }
        else
        {
            res += (cur * ap(nxt + 1, arr[i] - nxt));
            k -= (cur * (arr[i] - nxt));
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}