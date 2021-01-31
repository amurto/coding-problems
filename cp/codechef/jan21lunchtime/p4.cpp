#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    ll k, v;
    cin >> n >> k;
    while (k % 2 == 0)
        k /= 2;
    bool res = true;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        while (v % 2 == 0)
            v /= 2;
        if (v % k != 0)
            res = false;
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
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}