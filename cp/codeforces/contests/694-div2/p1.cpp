#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll mn = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        mn += arr[i];
        mx += (arr[i] + x - 1) / x;
    }
    mn = (mn + x - 1) / x;
    cout << mn << " " << mx << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}