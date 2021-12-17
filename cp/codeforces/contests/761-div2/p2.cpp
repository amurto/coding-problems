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
    int n, a = 0, b = 0, c = 0;
    cin >> n;
    if (n % 2 == 0)
    {
        c = 1;
        a = n / 2;
        b = a - 1;
    }
    else
    {
        c = 1;
        a = -1;
        n--;
        for (int i = 3; a == -1 && i <= n; i++)
            if (__gcd(i, n - i) == 1)
                a = i;
        b = n - a;
    }
    cout << a << " " << b << " " << c << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}