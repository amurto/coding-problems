#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, b;
    ll m;
    cin >> n >> m;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<ll>> d(2);
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        d[b - 1].pb(a[i]);
    }
    int p = 0;
    sort(d[0].rbegin(), d[0].rend());
    sort(d[1].rbegin(), d[1].rend());
    int i1 = 0, i2 = 0;
    while (m > 0 && i1 < d[0].size() && i2 < d[1].size())
    {
        if (d[0][i1] >= m || d[0][i1] >= d[1][i2])
        {
            m -= d[0][i1++];
            p++;
            continue;
        }
        if (i1 == d[0].size() - 1 || (d[1][i2] >= (d[0][i1] + d[0][i1 + 1])))
        {
            m -= d[1][i2++];
            p += 2;
        }
        else
        {
            m -= d[0][i1++];
            p++;
        }
    }
    while (m > 0 && i1 < d[0].size())
    {
        m -= d[0][i1++];
        p++;
    }
    while (m > 0 && i2 < d[1].size())
    {
        m -= d[1][i2++];
        p += 2;
    }
    return (m <= 0) ? p : -1;
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