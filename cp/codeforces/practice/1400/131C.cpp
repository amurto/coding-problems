// https://codeforces.com/contest/131/problem/C
// The World is a Theatre

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

vector<vector<ll>> ncr(31);
void pascal()
{
    ncr[1].pb(1);
    ncr[1].pb(1);
    for (ll i = 2; i <= 30; i++)
    {
        ncr[i].pb(1);
        for (ll j = 1; j <= i - 1; j++)
            ncr[i].pb(ncr[i - 1][j] + ncr[i - 1][j - 1]);
        ncr[i].pb(1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pascal();
    int n, m, t;
    cin >> n >> m >> t;
    ll res = 0;
    for (int b = 4, g = t - 4; b < t; b++, g--)
    {
        if (b > n || g > m)
            continue;
        res += ncr[n][b] * ncr[m][g];
    }
    cout << res << "\n";
    return 0;
}