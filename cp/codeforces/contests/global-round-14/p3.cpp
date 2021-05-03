#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<ll> arr(n), ord(n), h(m), res(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](ll &i1, ll &i2) {
        return arr[i1] < arr[i2];
    });
    for (int i = 0, cur = 0; i < n; i++, cur++)
    {
        cur %= m;
        h[cur] += arr[ord[i]];
        res[ord[i]] = cur;
    }
    ll mx = 0, mn = 1e10;
    for (int i = 0; i < m; i++)
    {
        mn = min(mn, h[i]);
        mx = max(mx, h[i]);
    }
    if (mx - mn > x)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << res[i] + 1 << " ";
    cout << "\n";
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