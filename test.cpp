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
    ll n;
    cin >> n;
    if (n == 1)
        return true;
    if (n == 2)
        return false;
    if (n == 3)
        return true;
    if (n==4)
        return true;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Alice\n" : cout << "Bob\n";
    return 0;
}