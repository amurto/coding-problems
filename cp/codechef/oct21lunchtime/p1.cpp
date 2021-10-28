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
    ll k, res = -1;
    cin >> n >> k;
    int sz = n * n;
    vector<ll> arr(sz + 1);
    for (int i = 1; i <= sz; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int med = (n + 2) / 2;
    int rem = n - med;
    int h = med - 1, r = sz - (n * rem);
    ll cur_sum = 0;
    for (int i = r - n + 1; i <= r; i++)
        cur_sum += arr[i];
    if (cur_sum <= k)
        res = max(res, arr[r - n + 1]);
    int l = r - n + 1;
    for (int i = 1; i < n; i++)
    {
        int itr = h;
        r--;
        while (itr > 0 && l > 0)
        {
            cur_sum -= arr[r];
            l--;
            r--;
            cur_sum += arr[l];
            if (cur_sum <= k)
                res = max(res, arr[l]);
            itr--;
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