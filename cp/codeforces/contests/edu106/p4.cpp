#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e7 + 5;

// O(n)
vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

ll f(int c, int d, int r)
{
    if ((d + r) % c > 0)
        return 0;
    int req = (d + r) / c;
    ll res = 1;
    while (req > 1)
    {
        int div = lp[req];
        res *= 2;
        while (req % div == 0)
            req /= div;
    }
    return res;
}

ll solve()
{
    int c, d, x;
    ll res = 0;
    cin >> c >> d >> x;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            res += f(c, d, x / i);
            if ((i * i) != x)
            {
                int q = x / i;
                res += f(c, d, x / q);
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}