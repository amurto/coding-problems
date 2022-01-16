#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e6 + 5;
int mob[N];
// O(n)
vector<int> lp(N + 1), pr;
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

ll nc2(int x)
{
    return (x * 1ll * (x - 1)) / 2;
}

int solve()
{
    int n, mx = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    vector<bool> vis(mx + 1);
    vector<int> cnt(mx + 1);
    for (int i = 0; i < n; i++)
        vis[arr[i]] = true;
    for (int i = mx; i > 0; i--)
    {
        for (int j = i; j <= mx; j += i)
            cnt[i] += vis[j];
        if (!vis[i])
        {
            ll val = 0;
            for (int j = i, k = 1; j <= mx; j += i, k++)
                if (cnt[j] > 0)
                    val += (1ll * mob[k] * nc2(cnt[j]));
            if (val >= 1)
            {
                vis[i] = true;
                cnt[i]++;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= mx; i++)
        if (vis[i])
            res++;
    return res - n;
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