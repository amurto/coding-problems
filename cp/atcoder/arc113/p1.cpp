#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll d(int k)
{
    ll res = 0;
    for (int i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            res++;
            if (i * i != k)
                res++;
        }
    }
    return res;
}

ll solve()
{
    int k;
    cin >> k;
    ll res = 0;
    for (int i = 1; i <= k; i++)
        res += d(i) * 1ll * (k / i);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}