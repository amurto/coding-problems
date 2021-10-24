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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int itr = 0;
    if (n & 1)
    {
        itr = 3;
        b[0] = abs(a[1]) + abs(a[2]);
        b[1] = abs(a[0]);
        b[2] = abs(a[0]);
        if ((a[0] * b[0]) > 0)
            b[0] *= -1;
        if ((a[1] * b[1]) < 0)
            b[1] *= -1;
        if ((a[2] * b[2]) < 0)
            b[2] *= -1;
    }
    for (int i = itr; i < n; i += 2)
    {
        b[i] = -a[i + 1];
        b[i + 1] = a[i];
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << "\n";
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