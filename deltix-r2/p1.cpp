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

int solve()
{
    int c, d;
    cin >> c >> d;
    if (c < d)
        swap(c, d);
    int diff = c - d;
    if (c + d == 0)
        return 0;
    if (c == d)
        return 1;
    if (diff & 1)
        return -1;
    return 2;
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