#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    vector<ll> pre(n);
    vector<bool> vis(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());

    pre[0] = arr[0].first;
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + arr[i].first;
    vis[arr[n - 1].second] = true;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i].first == arr[i + 1].first)
        {
            vis[arr[i].second] = vis[arr[i + 1].second];
            continue;
        }
        if (pre[i] >= arr[i + 1].first)
            vis[arr[i].second] = vis[arr[i + 1].second];
        else
            vis[arr[i].second] = false;
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
        if (vis[i])
            res.pb(i);
    cout << res.size() << "\n";
    for (int r : res)
        cout << r << " ";
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