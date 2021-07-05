#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> arr(n), ids(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return arr[i1] < arr[i2]; });

    ll d = k / n;
    vector<ll> res(n, d);
    k %= n;
    for (int i = 0; i < k; i++)
        res[ids[i]]++;
    for (ll e : res)
        cout << e << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}