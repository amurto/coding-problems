#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double solve()
{
    int n;
    ll v, k, mx = 0;
    cin >> n >> k;
    vector<ll> arr, p;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        arr.pb(v);
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i++)
    {
        mx = max(mx, arr[i] - arr[i - 1] - 1);
        p.pb((arr[i] - arr[i - 1]) / 2);
    }
    if (arr[0] != 1)
        p.pb(arr[0] - 1);
    if (arr.back() != k)
        p.pb(k - arr.back());
    p.pb(0);
    p.pb(0);
    sort(p.rbegin(), p.rend());
    mx = max(mx, p[0] + p[1]);
    return (1.0 * mx) / (1.0 * k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}