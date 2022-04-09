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

const int MX = 32768;
int calc(int x)
{
    x %= MX;
    if (x == 0)
        return 0;
    int z = 0;
    while (x % 2 == 0)
    {
        z++;
        x /= 2;
    }
    return 15 - z;
}

int solve()
{
    int x, res = 15;
    cin >> x;
    for (int i = 0; i <= 15; i++)
        res = min(res, i + calc(x + i));
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
        cout << solve() << " ";
    return 0;
}