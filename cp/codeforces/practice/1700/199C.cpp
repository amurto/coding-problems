// https://codeforces.com/contest/199/problem/C
// About Bacteria

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll k, b, n, t, cur = 1;
    cin >> k >> b >> n >> t;
    while (cur < t && n > 0)
    {
        cur = cur * k + b;
        n--;
    }
    if (t >= cur)
        return n;
    return n + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}