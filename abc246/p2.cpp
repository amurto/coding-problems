#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int a, b;
    cin >> a >> b;
    double x = 0, y = 0;
    if (a == 0)
    {
        x = 0;
        y = 1;
    }
    else
    {
        double m = (1.0 * b) / (1.0 * a);
        x = (1 / sqrt(1 + (m * m)));
        y = m * x;
    }
    cout << x << " " << y << "\n";
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