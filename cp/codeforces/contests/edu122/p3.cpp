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

bool valid(ll hc, ll dc, ll hm, ll dm)
{
    ll t1 = (hm + dc - 1) / dc, t2 = (hc + dm - 1) / dm;
    if (t1 <= t2)
        return true;
    return false;
}
bool solve()
{
    ll hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    for (int i = 0; i <= k; i++)
        if (valid(hc + a * i, dc + w * (k - i), hm, dm))
            return true;
    return false;
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