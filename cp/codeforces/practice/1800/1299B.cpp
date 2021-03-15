// https://codeforces.com/contest/1299/problem/B
// Aerodynamic

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll dis(ll x1, ll y1, ll x2, ll y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool solve()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n), d(n), num(n), den(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    if (n & 1)
        return false;
    int h = n / 2;
    for (int i = 1; i < n; i++)
    {
        d[i] = dis(x[i - 1], y[i - 1], x[i], y[i]);
        num[i] = y[i] - y[i - 1];
        den[i] = x[i] - x[i - 1];
    }
    d[0] = dis(x[n - 1], y[n - 1], x[0], y[0]);
    num[0] = y[0] - y[n - 1];
    den[0] = x[0] - x[n - 1];
    for (int i = 0; i < n; i++)
    {
        int m = i + h;
        if (m >= n)
            m %= n;
        if (d[i] != d[m] || num[i] * den[m] != num[m] * den[i])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}