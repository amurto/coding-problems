// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1450
// 10509 - R U Kidding Mr. Feynman?

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double n;
    while (cin >> n && n)
    {
        int l = 1, r = 100, res = 0;
        while (l < r)
        {
            int mid = (r + l + 1) / 2;
            if (n >= 1.0 * mid * mid * mid)
                l = mid;
            else
                r = mid - 1;
        }
        double a = r * 1.0;
        double dx = (n - a * a * a) / 3.0 / a / a;
        cout << fixed << setprecision(4) << (a + dx) << "\n";
    }
    return 0;
}