// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1432
// 10491 - Cows and Cars

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c1, c2, d;
    while (cin >> c1)
    {
        cin >> c2 >> d;
        int t = c1 + c2;
        double p = (c2 * 1.0 * (t - 1)) / (t * 1.0 * (t - d - 1));
        cout << fixed << setprecision(5) << p << "\n";
    }
    return 0;
}