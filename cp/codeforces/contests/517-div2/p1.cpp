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
    int w, h, k, res = 0;
    cin >> w >> h >> k;
    while (k > 0)
    {
        res += 2 * h + 2 * w - 4;
        w -= 4;
        h -= 4;
        k--;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}