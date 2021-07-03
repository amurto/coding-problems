#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    ll n, a, b;
    cin >> n >> a >> b;
    if (a == 1)
        return ((n - 1) % b == 0);
    ll cur = 1;
    while (cur <= n)
    {
        if ((n - cur) % b == 0)
            return true;
        cur *= a;
    }
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
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}