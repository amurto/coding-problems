// https://codeforces.com/contest/257/problem/C
// View Angle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double pi = 4.0 * atan(1.0);
    int n, x, y;
    cin >> n;
    vector<double> ang(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        ang[i] = atan2(y, x) * 180 / pi;
    }
    sort(ang.rbegin(), ang.rend());
    double res = 360.0;
    for (int i = 1; i < n; i++)
        res = min(res, 360.0 - (ang[i - 1] - ang[i]));
    res = min(res, ang[0] - ang[n - 1]);
    cout << fixed << setprecision(12) << res << "\n";
    return 0;
}