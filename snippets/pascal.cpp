// Pascal's Triangle
// Precomputes NCR
// ncr[i][j] = ncr(i, j);

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
    return 0;
}