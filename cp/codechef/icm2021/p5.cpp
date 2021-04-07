#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

long double solve()
{
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    long double s = (a + b + c) / 2.0;
    long double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return (k / ((k + 1) * 1.0)) * area;
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