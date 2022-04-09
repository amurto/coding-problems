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

const ll inf = 1e18;

bool calc(vector<ll> arr, int n, ll mx, ll ops)
{
    ll ones = (ops + 1) / 2, twos = ops / 2;
    for (int i = 0; i < n; i++)
    {
        ll req = min(twos, (mx - arr[i]) / 2);
        arr[i] += req * 2;
        twos -= req;

        req = min(ones, mx - arr[i]);
        arr[i] += req;
        ones -= req;
    }
    for (ll v : arr)
        if (v != mx)
            return false;
    return true;
}

ll solve()
{
    int n;
    cin >> n;
    ll res = inf, mx = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    ll low = 0, high = 1e17;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (calc(arr, n, mx, mid) || calc(arr, n, mx + 1, mid))
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
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