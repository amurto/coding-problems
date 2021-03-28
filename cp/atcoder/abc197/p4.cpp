#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double dis(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void solve()
{
    int n;
    cin >> n;
    double x0, y0, xh, yh;
    cin >> x0 >> y0 >> xh >> yh;
    double d = dis(x0, y0, xh, yh);
    cout << d << "\n";
    double s = d / 2.0 * 2.0 * sin(180.0 / n);
    cout << s << "\n";
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