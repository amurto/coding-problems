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

ll solve()
{
    int n;
    ll res = 0;
    ll k, x;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        ll req = min(k, arr[i] / x);
        k -= req;
        arr[i] -= req * x;
    }
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < n; i++)
    {
        if (k > 0)
        {
            k--;
            arr[i] = 0;
        }
        res += arr[i];
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