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

const int N = 2e7 + 5;
int cnt[N], st[N], lp[N];
ll dp[N];

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<int> arr(n);
    memset(cnt, 0, sizeof(cnt));
    memset(st, 0, sizeof(st));
    memset(dp, 0, sizeof(dp));
    memset(lp, 0, sizeof(lp));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        st[arr[i]]++;
    }
    int mx = *max_element(arr.begin(), arr.end());
    mx++;
    vector<int> pr;
    for (int i = 2; i < N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    for (int i = 1; i < mx; i++)
        for (int j = i; j < mx; j += i)
            cnt[i] += st[j];
    dp[1] = n;
    for (int i = 1; i < mx; i++)
    {
        if (dp[i] > 0)
        {
            for (int x : pr)
            {
                ll j = i * 1ll * x;
                if (j >= mx)
                    break;
                if (cnt[j] > 0)
                    dp[j] = max(dp[j], dp[i] - (1ll * i * cnt[j]) + (1ll * j * cnt[j]));
            }
        }
        res = max(res, dp[i]);
    }
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