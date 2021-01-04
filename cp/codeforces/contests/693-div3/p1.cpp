#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    ll w, h, n, p = 1;
    cin >> w >> h >> n;
    while (w % 2 == 0)
    {
        p *= 2;
        w /= 2;
    }
    while (h % 2 == 0)
    {
        p *= 2;
        h /= 2;
    }
    return p >= n;
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