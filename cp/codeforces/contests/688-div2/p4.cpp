#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll k;
    cin >> k;
    if (k & 1)
    {
        cout << "-1\n";
        return;
    }
    vector<int> res;
    k -= 2;
    res.pb(1);
    while (k > 0)
    {
        ll last = 2, cur = 2, p = 4, i = 0;
        while (cur <= k)
        {
            last = cur;
            p *= 2;
            cur = p - 2;
            i++;
        }
        i--;
        while (i-- > 0)
            res.pb(0);
        res.pb(1);
        k -= last;
    }
    cout << res.size() << "\n";
    for (int r : res)
        cout << r << " ";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}