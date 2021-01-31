#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    ll k, res = 0;
    cin >> n >> k;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    ll cur = p[0];
    for (int i = 1; i < n; i++)
    {
        if (p[i] * 100 > cur * k)
        {
            ll c = p[i] * 100 / k;
            ll nc = c * k;
            while (nc < (p[i] * 100))
            {
                nc += k;
                c++;
            }
            res += c - cur;
            cur += c - cur;
        }
        cur += p[i];
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