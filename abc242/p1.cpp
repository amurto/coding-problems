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

double solve()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    if (x <= a)
        return 1;
    if (x > b)
        return 0;
    return (1.0 * c) / (1.0 * (b - a));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << solve() << "\n";
    return 0;
}