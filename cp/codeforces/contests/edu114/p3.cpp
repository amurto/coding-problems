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

const ll inf = 2e18;
void solve()
{
    int n, m;
    cin >> n;
    ll sum = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(), arr.end());
    cin >> m;
    vector<ll> x(m), y(m);
    for (int i = 0; i < m; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < m; i++)
    {
        ll mn = inf;
        int r = lower_bound(arr.begin(), arr.end(), x[i]) - arr.begin();
        int l = r - 1;
        if (r < n)
            mn = min(mn, max(0ll, y[i] - sum + arr[r]));
        if (l >= 0)
            mn = min(mn, x[i] - arr[l] + max(0ll, y[i] - sum + arr[l]));
        cout << mn << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}