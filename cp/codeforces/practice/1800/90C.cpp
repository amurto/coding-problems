// https://codeforces.com/contest/90/problem/C
// Robbery

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n, m, k, mn = 1e6;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n % 2 == 0)
        return 0;
    for (int i = 0; i < n; i++)
        if (i % 2 == 0)
            mn = min(mn, arr[i]);
    ll req = m / ((n + 1) / 2);
    return min(k * req, mn);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}