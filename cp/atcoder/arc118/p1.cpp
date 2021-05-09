#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll tax(ll t, ll n)
{
    return ((100 + t) * n) / 100;
}
ll solve()
{
    ll t, n;
    cin >> t >> n;
    ll low = 1, high = 1e15, res = 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll tt = tax(t, mid) - mid;
        if (tt < n)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res + n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}