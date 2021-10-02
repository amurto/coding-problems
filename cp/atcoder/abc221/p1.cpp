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

ll pw(int x)
{
    if (x == 0)
        return 1;
    return 1ll * 32 * pw(x - 1);
}
ll solve()
{
    int a, b;
    cin >> a >> b;
    return pw(a - b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}