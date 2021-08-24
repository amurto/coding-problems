#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

ll solve()
{
    int n, k;
    ll x, res = 0;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
        return arr[0];
    if (k == 0)
    {
        for (ll a : arr)
            res += a;
        return res;
    }
    sort(arr.begin(), arr.end());
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (arr[i - 1] + arr[i] > x)
            idx = max(idx, n - i + 1);
    int rem = min(idx, 2 * k);
    if (rem & 1)
        rem--;
    res += x * (rem / 2);
    for (int i = 0; i < n - rem; i++)
        res += arr[i];
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