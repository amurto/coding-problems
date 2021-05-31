#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int dis = abs(a - c) + abs(b - d);
    return dis <= k && dis % 2 == k % 2;
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