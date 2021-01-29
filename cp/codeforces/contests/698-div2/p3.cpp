#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    vector<ll> d(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> d[i];
    sort(d.rbegin(), d.rend());
    for (int i = 2; i < d.size(); i++)
        if (d[i] == d[i - 2])
            return false;
    ll sf = 0;
    for (int i = 0, c = n; i < 2 * n; i += 2, c--)
    {
        if (d[i] != d[i + 1] || (d[i] == 0 || d[i] & 1) | (d[i + 1] == 0 || d[i + 1] & 1))
            return false;
        ll tmp = d[i];
        tmp -= sf;
        if (tmp <= 0 || tmp % c > 0)
            return false;
        tmp /= c;
        if (tmp & 1)
            return false;
        sf += tmp;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}