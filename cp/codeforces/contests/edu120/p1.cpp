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

bool calc(int a, int b, int c)
{
    if (a == (b + c))
        return true;
    return a % 2 == 0 && b == c;
}
bool solve()
{
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    return calc(l1, l2, l3) || calc(l2, l1, l3) || calc(l3, l1, l2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}