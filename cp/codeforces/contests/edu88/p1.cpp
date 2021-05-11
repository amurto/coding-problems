#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int c = n / k;
    int mx = min(c, m);
    m -= mx;
    k--;
    if (k == 0)
        return mx;
    int mn = (m + k - 1) / k;
    return mx - mn;
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