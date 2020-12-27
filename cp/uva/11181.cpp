// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2122
// 11181 - Probability|Given

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int countBits(int n)
{
    int bits = 0;
    while (n > 0)
    {
        bits += (n & 1);
        n >>= 1;
    }
    return bits;
}

double findProb(vector<double> &p, int n, int mask)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        if ((mask >> i) & 1)
            ans *= p[i];
        else
            ans *= (1.0 - p[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(6);
    int n, r, tc = 1;
    while (cin >> n >> r && (n | r))
    {
        vector<double> p(n), res(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        double total = 0;
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (countBits(mask) == r)
            {
                double prob = findProb(p, n, mask);
                for (int j = 0; j < n; j++)
                    if ((mask >> j) & 1)
                        res[j] += prob;
                total += prob;
            }
        }
        cout << "Case " << tc++ << ":\n";
        for (double pr : res)
            cout << (pr / total) << "\n";
    }
    return 0;
}