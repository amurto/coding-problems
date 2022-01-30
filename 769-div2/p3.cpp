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
    int a, b, res = 1e9;
    cin >> a >> b;
    for (int j = b; j >= 0; j = (j - 1) & b)
    {
        // mask is original set
        // j is subset
        if (j >= a)
            res = min(res, j - a + 1);
        if (j == 0)
            break;
    }
    for (int j = a; j < (1 << 25); j = (j + 1) | a)
    {
        // mask is original set
        // j is superset
        // j ^ mask is added subset
        if (j >= b)
        {
            res = min(res, j - b + 1);
            break;
        }
    }
    res = min(res, b - a);
    return res;
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