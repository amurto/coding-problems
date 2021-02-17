// https://codeforces.com/contest/672/problem/C
// Recycling Bottles

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double dis(ll x1, ll y1, ll x2, ll y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double solve()
{
    ll ax, ay, bx, by, tx, ty, x, y;
    int n;
    cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
    ll X[n + 2], Y[n + 2];
    double cur[n + 2], pre[n + 2], suf[n + 2], trash = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> X[i] >> Y[i];
        cur[i] = dis(tx, ty, X[i], Y[i]);
        trash += 2 * cur[i];
        pre[i] = suf[i] = dis(ax, ay, X[i], Y[i]) - cur[i];
        cur[i] = dis(bx, by, X[i], Y[i]) - cur[i];
    }
    pre[0] = suf[n + 1] = 1e18 + 5;
    for (int i = 1; i <= n; i++)
        pre[i] = min(pre[i - 1], pre[i]);
    for (int i = n; i >= 1; i--)
        suf[i] = min(suf[i + 1], suf[i]);
    double res = trash + suf[1];
    for (int i = 1; i <= n; i++)
        res = min(res, trash + min(0.0, min(pre[i - 1], suf[i + 1])) + cur[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12) << solve() << "\n";
    return 0;
}