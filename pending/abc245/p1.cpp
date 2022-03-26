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
    int t1a, t1b, t2a, t2b;
    cin >> t1a >> t1b >> t2a >> t2b;
    return t1a < t2a || (t1a == t2a && t1b <= t2b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Takahashi\n" : cout << "Aoki\n";
    return 0;
}