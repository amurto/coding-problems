// https://codeforces.com/contest/1225/problem/D
// Power Products

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll LIM1 = 1e5, LIM2 = 1e10;
void fac(map<ll, ll> &mp, ll x, int k, ll &res)
{
    ll cur = 1, req = 1;
    for (ll i = 2; cur * req <= LIM2 && i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                x /= i;
                cnt++;
            }
            cnt %= k;
            int tmp = (k - cnt) % k;
            while (cur <= LIM1 && cnt-- > 0)
                cur *= i;
            while (req <= LIM1 && tmp-- > 0)
                req *= i;
        }
    }
    if (cur > LIM1 || req > LIM1)
        return;
    if (x > 1)
    {
        cur *= x;
        int tmp = k - 1;
        while (tmp <= LIM1 && tmp-- > 0)
            req *= x;
    }
    if (cur > LIM1 || req > LIM1)
        return;
    res += mp[req];
    mp[cur]++;
}

ll solve()
{
    int n, k;
    ll x, res = 0;
    cin >> n >> k;
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        fac(mp, x, k, res);
    }
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