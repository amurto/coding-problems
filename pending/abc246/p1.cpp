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
    vector<int> x(4), y(4);
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    if (x[0] == x[1])
        x[3] = x[2];
    else if (x[0] == x[2])
        x[3] = x[1];
    else
        x[3] = x[0];
    if (y[0] == y[1])
        y[3] = y[2];
    else if (y[0] == y[2])
        y[3] = y[1];
    else
        y[3] = y[0];
    cout << x[3] << " " << y[3] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}