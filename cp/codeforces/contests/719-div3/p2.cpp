#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll n, res = 0;
    cin >> n;
    for (ll i = 1; i <= 9; i++)
    {
        ll cur = i;
        while (cur <= n)
        {
            res++;
            cur = cur * 10 + i;
        }
    }
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