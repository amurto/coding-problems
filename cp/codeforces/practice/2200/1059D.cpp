// https://codeforces.com/contest/1059/problem/D
// Nature Reserve

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back

class Point
{
public:
    ld x, y;
    Point(const ld x, const ld y) : x(x), y(y){};
};

ld sq(ld v)
{
    return v * v;
}

ld f(vector<Point> &pts, ld x0)
{
    // Center is (x0, R)
    // Find R
    // Point(xi, yi)
    // R^2 = (x0-xi)^2 + (R-yi)^2
    // Let v = (x0-xi)^2
    // R^2 = v + R^2 - (2*R*yi) + yi^2
    // 2*R*yi = v + yi^2
    // R = (v + yi^2)/(2*yi);
    ld R = 0.0;
    for (Point p : pts)
        R = max(R, (sq(x0 - p.x) + sq(p.y)) / (2.0 * p.y));
    return R;
}

void solve()
{
    int n, mn = 1e7 + 5, mx = -1e7 - 5;
    cin >> n;
    bool pos = false, neg = false;
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
        if (Y[i] > 0)
            pos = true;
        else
            neg = true;
        mn = min(mn, X[i]);
        mx = max(mx, X[i]);
    }
    if (pos && neg)
    {
        cout << "-1\n";
        return;
    }
    if (neg)
        for (int i = 0; i < n; i++)
            Y[i] = -Y[i];
    vector<Point> pts;
    for (int i = 0; i < n; i++)
        pts.pb(Point(X[i], Y[i]));
    ld low = 1.0 * mn, high = 1.0 * mx;
    for (int t = 1; t <= 100; t++)
    {
        ld m1 = low + (high - low) / 3.0;
        ld m2 = high - (high - low) / 3.0;
        ld f1 = f(pts, m1); //evaluates the function at m1
        ld f2 = f(pts, m2); //evaluates the function at m2
        if (f1 < f2)
            high = m2;
        else
            low = m1;
    }
    cout << f(pts, low) << "\n";
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