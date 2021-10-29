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

ll tw[10];
ll solve()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> arr(n), vis(100);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll res = 0, t = 1, i = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = arr[i];
        ll c = 0;
        if (i == n - 1)
            res += tw[arr[i]] * (k + 1);
        else
        {
            while (cur < arr[i + 1])
            {
                c += tw[cur] * 9;
                cur++;
            }
            ll req = c / tw[arr[i]];
            if (req <= k)
            {
                k -= req;
                res += c;
            }
            else
            {
                res += tw[arr[i]] * (k + 1);
                i = n;
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
    tw[0] = 1;
    for (int i = 1; i < 10; i++)
        tw[i] = tw[i - 1] * 10;
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}