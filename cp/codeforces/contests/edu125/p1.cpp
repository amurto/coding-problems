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

bool is_sq(int v)
{
    int i = 1;
    while (i * i < v)
        i++;
    return (i * i) == v;
}

int solve()
{
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0)
        return 0;
    if (is_sq(x * x + y * y))
        return 1;
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