// https://codeforces.com/contest/408/problem/C
// Triangle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int sq_root(int e)
{
    int l = 1, r = e;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (mid * mid > e)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

bool op(int a, int b)
{
    for (int x = 1; x < a; x++)
    {
        int y = sq_root(a * a - x * x);
        if (x * x + y * y != a * a)
            continue;
        int gx = x / __gcd(x, y), gy = y / __gcd(x, y);
        int blen = sq_root(gx * gx + gy * gy);
        if (b % blen > 0)
            continue;
        int m = b / blen;
        gy *= -m;
        gx *= m;
        if (abs(gx) == y)
            continue;
        cout << "YES\n";
        cout << x << " " << y << "\n";
        cout << "0 0\n";
        cout << gy << " " << gx << "\n";
        return true;
    }
    return false;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    if (op(a, b) || op(b, a))
        return;
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}