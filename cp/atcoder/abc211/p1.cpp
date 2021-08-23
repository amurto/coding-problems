#ifdef use_debug
#define TERMINAL
#include "Headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double solve()
{
    int a, b;
    cin >> a >> b;
    d(a);
    return (1.0 * (a - b)) / 3.0 + 1.0 * b;
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