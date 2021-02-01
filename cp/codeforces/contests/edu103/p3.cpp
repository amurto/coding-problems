#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    ll cur = abs(b[1] - a[1]) + 1 + c[1];
    ll res = cur;
    for (int i = 2; i < n; i++)
    {
        if (a[i] == b[i])
        {
            cur = 1 + c[i];
        }
        else
        {
            ll d = abs(b[i] - a[i]) + 1;
            cur = max(cur - abs(b[i] - a[i]) + 1, d) + c[i];
        }
        res = max(res, cur);
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