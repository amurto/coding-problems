// https://codeforces.com/contest/312/problem/B
// Archer

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int rx = (b - a) * (d - c), ry = b * d;
    double p = (1.0 * a) / (1.0 * b), r = (1.0 * rx) / (1.0 * ry);
    return p / (1.0 - r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cout << solve() << "\n";
    return 0;
}