#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    ll sum = a + b + c;
    int mn = min({a, b, c});
    if (sum % 9 == 0 && sum / 9 <= mn)
        return true;
    return false;
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