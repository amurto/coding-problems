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

bool solve()
{
    ll a, b;
    cin >> a >> b;
    while (a > 0 && b > 0)
    {
        if ((a % 10) + (b % 10) >= 10)
            return true;
        a /= 10;
        b /= 10;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Hard\n" : cout << "Easy\n";
    return 0;
}