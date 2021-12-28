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

const ll inf = 1e16;

ll solve()
{
    int n;
    ll k, sum = 0;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum <= k)
        return 0;
    ll res = max(0ll, sum - k);
    sort(arr.begin(), arr.end());
    if (n > 1)
        reverse(arr.begin() + 1, arr.end());
    vector<ll> suf(n + 1);
    for (int i = n - 1; i >= 0; i--)
        suf[i] = arr[i] + suf[i + 1];
    ll cnt = 1;
    for (int i = 1; i < n; i++)
    {
        ll suf_sum = suf[i + 1];
        if (arr[0] == arr[i])
            cnt++;
        ll tmp = arr[0] * 1ll * (i + 1) + suf_sum;
        res = min(res, max(0ll, tmp - k) + i + 1 - cnt);
        ll low = 1, high = (sum + i) / (i + 1);
        while (low < high)
        {
            ll mid = low + (high - low) / 2, e = i + 1;
            if ((arr[0] - mid) * e + suf_sum <= k)
                high = mid;
            else
                low = mid + 1;
        }
        res = min(res, low + i);
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