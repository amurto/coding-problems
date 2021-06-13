#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n + 1), diff(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        diff[i] = arr[i] - arr[i - 1] - 1;
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + diff[i];
    for (int tc = 0; tc < q; tc++)
    {
        ll k;
        cin >> k;
        if (k > pre.back())
        {
            k -= pre.back();
            cout << arr.back() + k << "\n";
        }
        else
        {
            int id = lower_bound(pre.begin(), pre.end(), k) - pre.begin();
            id--;
            ll x = k - pre[id];
            cout << arr[id] + x << "\n";
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