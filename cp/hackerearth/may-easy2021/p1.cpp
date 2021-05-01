#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    map<ll, ll> mp1, mp2;
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll ai = arr[i] + i * i, aj = arr[i] - i * i;
        mp1[ai]++;
        mp2[aj]++;
    }
    for (auto x : mp1)
        res += x.second * mp2[x.first];
    cout << res << "\n";
    return 0;
}