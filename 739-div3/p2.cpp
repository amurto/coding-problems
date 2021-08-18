#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int diff = abs(a - b);
    if (max(a, max(b, c)) > 2 * diff)
        return -1;
    if (c > diff)
        return c - diff;
    return c + diff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}