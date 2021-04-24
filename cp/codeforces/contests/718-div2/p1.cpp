#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n, x = 2050, res = 0;
    cin >> n;
    while (n >= 2050)
    {
        ll cur = x;
        while (cur * 10 <= n)
            cur *= 10;
        res += n / cur;
        n %= cur;
    }
    if (n > 0)
        return -1;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}