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

char solve()
{
    int v, a, b, c;
    cin >> v >> a >> b >> c;
    int sum = a + b + c;
    v %= sum;
    if (a > v)
        return 'F';
    v -= a;
    if (b > v)
        return 'M';
    v -= b;
    return 'T';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}