#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), res;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        p[i].first = arr[i];
        p[i].second = i;
    }
    sort(p.rbegin(), p.rend());
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (vis[p[i].second])
            continue;
        for (int j = p[i].second; j < n && !vis[j]; j++)
        {
            res.pb(arr[j]);
            vis[j] = true;
        }
    }
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