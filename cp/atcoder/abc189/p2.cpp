#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    ll x;
    cin >> n >> x;
    x *= 100;
    vector<ll> v(n), p(n);
    for (int i = 0; i < n; i++)
        cin >> v[i] >> p[i];
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += v[i] * p[i];
        if (cur > x)
            return i + 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}