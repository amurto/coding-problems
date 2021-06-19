#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5;
vector<int> lp(N + 1), pr;
int mob[N];
void mobius()
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
    for (int i = 1; i < N; i++)
    {
        if (i == 1)
            mob[i] = 1;
        else
        {
            if (lp[i / lp[i]] == lp[i])
                mob[i] = 0;
            else
                mob[i] = -1 * mob[i / lp[i]];
        }
    }
}

ll solve()
{
    int l, r;
    cin >> l >> r;
    ll res = 0;
    for (int i = 1; i <= r; i++)
    {
        int t = r / i - (l - 1) / i;
        res += 1ll * mob[i] * t * t;
    }
    res = 1ll * (r - l + 1) * (r - l + 1) - res;
    for (int i = max(2, l); i <= r; i++)
    {
        int t = r / i - (l - 1) / i;
        res -= 2ll * t;
        res++;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mobius();
    cout << solve() << "\n";
    return 0;
}