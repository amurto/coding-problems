#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const long double PI = 3.14159265358979;

long double solve()
{
    long double n;
    cin >> n;
    long double theta = (PI * (n - 2.0)) / n;
    long double r = sinl(theta / 2.0);
    r *= r;
    return 1.0 / (1.0 - r);
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