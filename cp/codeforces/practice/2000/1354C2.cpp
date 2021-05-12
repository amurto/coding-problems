// https://codeforces.com/contest/1354/problem/C2
// Not So Simple Polygon Embedding

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const double PI = 3.14159265358979;

double solve()
{
    int n;
    cin >> n;
    double theta = PI / (1.0 * n);
    double x = 1.0 / (2.0 * (1.0 - cos(theta)));
    x = sqrt(x);
    x *= 2.0;
    x *= x;
    double a = 2.0 * x * (1.0 - cos(PI / (2.0 * n)));
    a = sqrt(a);
    a /= 2.0;
    a *= a;
    double mid = sqrt(x - a);
    return mid;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}