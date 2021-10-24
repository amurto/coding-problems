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

ll calc(vector<ll> arr)
{
    int sz = (int)arr.size();
    ll mid = arr[sz / 2], res = 0;
    for (ll x : arr)
        res += abs(x - mid);
    return res;
}

ll solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    if (n == 2)
        return 0;
    ll res = min(calc(vector<ll>(arr.begin() + 1, arr.end())), calc(vector<ll>(arr.begin(), arr.end() - 1)));
    for (int i = n - 2; i > 0; i--)
    {
        ll diff = arr[i] - arr[0];
        if (i + 1 < n - 1)
            res = min(res, abs(abs(arr[n - 1] - arr[i + 1]) - diff));
        int id = lower_bound(arr.begin(), arr.end(), arr[n - 1] - diff) - arr.begin();
        for (int j = id; j <= min(i, id + 5); j++)
            if (j < i && j > 0)
                res = min(res, abs(abs(arr[n - 1] - arr[j]) - diff));
        for (int j = id - 1; j >= max(1, id - 5); j--)
            if (j < i && j > 0)
                res = min(res, abs(abs(arr[n - 1] - arr[j]) - diff));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}