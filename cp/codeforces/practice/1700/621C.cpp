// https://codeforces.com/contest/621/problem/C
// Wet Shark and Flowers

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
    ll p;
    cin >> n >> p;
    vector<pair<ll, ll>> r(n);
    vector<ll> d(n), gap(n);
    for (int i = 0; i < n; i++)
    {
        cin >> r[i].first >> r[i].second;
        d[i] = r[i].second / p - (r[i].first - 1) / p;
        gap[i] = r[i].second - r[i].first + 1;
    }
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        int prev = (i - 1 + n) % n;
        ll num = d[prev] * gap[i] + d[i] * gap[prev] - d[prev] * d[i];
        ll deno = gap[prev] * gap[i];
        res += num * 1.0 / deno;
    }
    res *= 2000;
    cout << fixed << setprecision(12) << res << "\n";
    return 0;
}