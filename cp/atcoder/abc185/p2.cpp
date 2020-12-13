#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    ll n, m, t;
    cin >> n >> m >> t;
    vector<pair<ll, ll>> arr(m);
    for (int i = 0; i < m; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    ll cap = n, last = 0;
    for (int i = 0; i < m; i++)
    {
        n -= (arr[i].first - last);
        if (n <= 0)
            return false;
        n += arr[i].second - arr[i].first;
        n = min(n, cap);
        last = arr[i].second;
    }
    n -= (t - arr[m - 1].second);
    if (n <= 0)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}