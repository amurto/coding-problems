#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

ll solve()
{
    int n;
    ll k, a, b;
    cin >> n >> k;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        mp[a] += b;
    }
    vector<pii> arr;
    for (auto x : mp)
        arr.pb({x.first, x.second});
    ll prev = 0;
    for (pii p : arr)
    {
        if (p.first - prev > k)
            return prev + k;
        k -= (p.first - prev);
        k += p.second;
        prev = p.first;
    }
    return prev + k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}