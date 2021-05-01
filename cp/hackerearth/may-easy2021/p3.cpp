#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n, m, k, b;
    cin >> n >> m >> k >> b;
    vector<ll> arr(n), pre(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + arr[i];
    ll res = b;
    for (int i = b; i < n; i++)
    {
        if (arr[i] == arr[b - 1])
        {
            res++;
            continue;
        }
        ll mx = arr[i] + m, rem = k - (b + n - i - 1);
        if (rem <= 0)
        {
            if (mx >= arr[b - 1])
                res++;
            continue;
        }
        if (arr[b - 1] <= mx)
        {
            // only [b-1...i-1] remaining
            ll sum = pre[i - 1];
            if (b - 1 > 0)
                sum -= pre[b - 2];
            if (mx * (i - b + 1) - sum >= m * rem)
                res++;
        }
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