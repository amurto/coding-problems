// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=997
// 10056 - What is the Probability ?

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// GP
// Answer is summation of infinite GP
// S = a/(1-r)
// Let q = 1-p
// q^m * p (1 + q^n + q^2n + q^3n + .... + inf)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        double p;
        cin >> n >> p >> k;
        if (p == 0)
            cout << "0.0000\n";
        else
        {
            double res = pow(1.0 - p, k - 1) * p / (1 - pow(1.0 - p, n));
            cout << fixed << setprecision(4) << res << "\n";
        }
    }
    return 0;
}