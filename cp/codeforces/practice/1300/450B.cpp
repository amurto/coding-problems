// https://codeforces.com/contest/450/problem/B
// Jzzhu and Sequences

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

vector<pair<ll, ll>> m = {
    {1, -1},
    {1, 0},
    {0, 1},
    {-1, 1},
    {-1, 0},
    {0, -1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x, y, n;
    cin >> x >> y >> n;
    ll res = x * m[n % 6].first + y * m[n % 6].second;
    while (res >= MOD)
        res -= MOD;
    while (res < 0)
        res += MOD;
    cout << res << "\n";
    return 0;
}