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
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i += 2)
    {
        ll op = 0, mn = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (j & 1)
                op += arr[j];
            else
            {
                ll l = arr[i], r = arr[j];
                l += mn;
                r -= op;
                if (j == i + 1)
                    res += min(l, r);
                else if (l >= 0 && r >= 0)
                    res += min(l, r) + 1;
                op -= arr[j];
                if (op < 0)
                    mn += op;
                op = max(0ll, op);
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
    cout << solve() << "\n";
    return 0;
}