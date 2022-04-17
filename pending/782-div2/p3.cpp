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

const ll inf = LLONG_MAX;
ll solve()
{
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<ll> arr(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    ll res = b * pre[n], cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur += ((a + b) * (arr[i] - arr[i - 1]));
        ll rem = n - i;
        ll dis = pre[n] - pre[i] - rem * arr[i];
        res = min(res, cur + b * dis);
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