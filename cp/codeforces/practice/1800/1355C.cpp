// https://codeforces.com/contest/1355/problem/C
// Count Triangles

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll a, b, c, d, res = 0;
    cin >> a >> b >> c >> d;
    vector<ll> pre(max(d + 5, b + c + 5));
    int sz = pre.size();
    for (ll x = a; x <= b; x++)
    {
        pre[x + b]++;
        pre[x + c + 1]--;
    }
    for (int i = 1; i < sz; i++)
        pre[i] += pre[i - 1];
    for (int i = 1; i < sz; i++)
        pre[i] += pre[i - 1];
    for (ll z = c; z <= d; z++)
        res += pre[sz - 1] - pre[z];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}