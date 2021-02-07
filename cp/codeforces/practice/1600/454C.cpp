// https://codeforces.com/contest/454/problem/C
// Little Pony and Expected Maximum

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Binary Exponentiation O(logn)
// n^m mod p
double power(double n, int m)
{
    double res = 1;
    while (m > 0)
    {
        if (m & 1)
            res *= n;
        n *= n;
        m /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> m >> n;
    double ans = 0, sum = 0;
    for (int i = m; i > 1; i--)
    {
        double cur = 1.0 - sum - power((i - 1) * 1.0 / m, n);
        sum += cur;
        ans += i * 1.0 * cur;
    }
    ans += power(1.0 / m, n);
    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}