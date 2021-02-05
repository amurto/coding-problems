// https://codeforces.com/contest/776/problem/C
// Molly's Chemicals

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll MIN = -1e14, MAX = 1e14;
map<ll, int> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    ll v, sum = 0, res = 0;
    vector<ll> p;
    p.pb(1);
    if (k != 1)
        p.pb(k);
    while (abs(k) != 1 && p.back() >= MIN && p.back() <= MAX)
        p.pb(p.back() * 1ll * k);
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        sum += v;
        for (int j = 0; j < p.size(); j++)
            res += mp[sum - p[j]];
        mp[sum]++;
    }
    cout << res << "\n";
    return 0;
}