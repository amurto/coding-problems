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
    int x;
    cin >> x;
    if (x < 40)
        cout << 40 - x << "\n";
    else if (x < 70)
        cout << 70 - x << "\n";
    else if (x < 90)
        cout << 90 - x << "\n";
    else
        cout << "expert\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}