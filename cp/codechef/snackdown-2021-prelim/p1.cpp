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

ll calc(ll a, ll b, ll c)
{
    return (c - b) * (b - a);
}

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 2; j < n; j++)
        {
            if (arr[j] - arr[i] > 0)
            {
                ll mid = arr[i] + (arr[j] - arr[i]) / 2, mx = 0;
                int id = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
                for (int k = id; k > max(i, id - 5); k--)
                    mx = max(mx, calc(arr[i], arr[k], arr[j]));
                for (int k = id; k < min(j, id + 5); k++)
                    mx = max(mx, calc(arr[i], arr[k], arr[j]));
                res += mx;
            }
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