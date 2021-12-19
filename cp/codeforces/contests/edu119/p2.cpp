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
    ll w, h;
    ll res = 0;
    cin >> w >> h;

    vector<vector<ll>> arr(4);
    for (int t = 0; t < 4; t++)
    {
        int k;
        cin >> k;
        arr[t].resize(k);
        for (int i = 0; i < k; i++)
            cin >> arr[t][i];
        sort(arr[t].begin(), arr[t].end());
        ll mx = arr[t][k - 1] - arr[t][0];
        if (t < 2)
            res = max(res, mx * h);
        else
            res = max(res, mx * w);
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