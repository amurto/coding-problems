#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const long double PI = 3.14159265358979;

pair<double, double> rotate(double px, double py, double ox, double oy, double theta)
{
    double x = cos(theta) * (px - ox) - sin(theta) * (py - oy) + ox;
    double y = sin(theta) * (px - ox) + cos(theta) * (py - oy) + oy;
    return {x, y};
}

void solve()
{
    int n;
    double x0, y0, xh, yh;
    cin >> n >> x0 >> y0 >> xh >> yh;
    double xm = (x0 + xh) / 2.0, ym = (y0 + yh) / 2.0;
    double theta = 2.0 * PI / (n * 1.0);
    pair<double, double> p1 = rotate(x0, y0, xm, ym, theta);
    cout << p1.first << " " << p1.second << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    solve();
    return 0;
}