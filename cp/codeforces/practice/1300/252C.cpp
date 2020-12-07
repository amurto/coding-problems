// https://codeforces.com/contest/252/problem/C
// Points on Line

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int L = 0, R = 1;
    ll p = 0;
    while (R < n)
    {

        if (L == R)
            R++;
        else if (abs(x[L] - x[R]) <= d)
        {
            p += (R - L) * 1ll * (R - L - 1) / 2;
            R++;
        }
        else
            L++;
    }
    cout << p << "\n";
    return 0;
}
