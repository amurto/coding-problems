#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> b(n), g(m);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
        cin >> g[i];
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    if (b[n - 1] > g[0])
        return -1;
    ll sum = 0;
    for (int i = 0; i < n; i++)
        sum += b[i] * m;
    if (n == 1)
    {
        if (b[n - 1] != g[0])
            return -1;
        for (int i = 0; i < m; i++)
            sum += g[i] - b[n - 1];
        return sum;
    }
    if (b[n - 1] == g[0])
    {
        for (int i = 0; i < m; i++)
            sum += g[i] - b[n - 1];
    }
    else
    {
        sum += g[0] - b[n - 2];
        for (int i = 1; i < m; i++)
            sum += g[i] - b[n - 1];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}