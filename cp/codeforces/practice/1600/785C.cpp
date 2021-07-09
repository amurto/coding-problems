// https://codeforces.com/contest/785/problem/C
// Anton and Fairy Tale

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll nc2(ll x)
{
    return (x * (x + 1)) / 2;
}
ll solve()
{
    ll n, m;
    cin >> n >> m;
    if (m >= n)
        return n;
    ll d = m;
    ll cap = n - m;
    ll low = 0, high = 2e9, res = 2e9;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (cap - nc2(mid) <= 0)
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res + d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}