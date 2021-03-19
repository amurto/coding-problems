#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, k1, k2, w, b, wp = 0, bp = 0;
    cin >> n >> k1 >> k2 >> w >> b;
    if (k1 > k2)
        swap(k1, k2);
    wp = k1 + abs(k2 - k1) / 2;
    bp = n - k2 + abs(k1 - k2) / 2;
    return wp >= w && bp >= b;
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