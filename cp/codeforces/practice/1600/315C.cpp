// https://codeforces.com/contest/315/problem/C
// Sereja and Contest

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll n, k, pre = 0;
    cin >> n >> k;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    ll e = 2, sz = n;
    for (int i = 2; i <= n; i++)
    {
        ll cur = pre + (e - 1) * 1ll * (-(sz - e) * 1ll * arr[i]);
        if (cur < k)
        {
            cout << i << "\n";
            sz--;
        }
        else
        {
            pre += arr[i] * (e - 1);
            e++;
        }
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