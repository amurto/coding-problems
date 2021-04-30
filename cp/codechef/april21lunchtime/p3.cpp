#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    ll w, wr;
    cin >> n >> w >> wr;
    vector<ll> arr(n);
    map<ll, int> mp;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        sum += 1ll * arr[i];
    }

    for (auto x : mp)
        if (x.second & 1)
            sum -= x.first;
    return (wr + sum) >= w;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}