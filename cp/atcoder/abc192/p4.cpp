#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool check(ll a, ll b, ll m)
{
    if (a == 0 || b == 0)
        return false;
    if (a > m / b)
        return true;
    return false;
}

bool pos(vector<ll> &dig, ll x, ll m)
{
    ll num = dig[0], cur = 1;
    for (int i = 1; i < dig.size(); i++)
    {
        if (check(cur, x, m))
            return false;
        cur *= x;
        if (check(cur, dig[i], m))
            return false;
        if (num > m - (cur * dig[i]))
            return false;
        num += cur * dig[i];
        if (num > m)
            return false;
    }
    return num <= m;
}

ll solve()
{
    string str;
    ll m, res = 0;
    cin >> str >> m;
    ll d = 0;
    vector<ll> dig;
    for (char s : str)
    {
        dig.pb((s - '0') * 1ll);
        d = max(d, dig.back());
    }
    reverse(dig.begin(), dig.end());
    if (dig.size() == 1)
    {
        if (dig[0] > m)
            return 0;
        return 1;
    }
    ll l = d + 1, r = 1e18;
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (pos(dig, mid, m))
        {
            res = max(res, mid - d);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if (pos(dig, l, m))
        res = max(res, l - d);
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