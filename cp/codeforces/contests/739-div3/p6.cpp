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

const int N = 10, K = 10;
ll dp[N][2][1 << K];
ll ten[N];
ll dfs(vector<int> &nums, int cur, int f, int mask, int k, int sz)
{
    if (__builtin_popcount(mask) > k)
        return -10;
    if (cur == sz)
        return 0ll;
    if (dp[cur][f][mask] == -1)
    {
        ll res = -10;
        int lim = nums[cur];
        if (f == 1)
            lim = 0;
        for (int i = lim; res==-10 &&i <= 9; i++)
        {
            int tmp_mask = (mask | (1 << i));
            int tmp_f = f;
            if (tmp_f == 0 && i > nums[cur])
                tmp_f++;
            ll v = dfs(nums, cur + 1, tmp_f, tmp_mask, k, sz);
            if (v >= 0)
            {
                ll ans = ten[sz - cur - 1] * i + v;
                if (res == -10)
                    res = ans;
            }
        }
        dp[cur][f][mask] = res;
    }
    return dp[cur][f][mask];
}

ll solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    while (n > 0)
    {
        nums.pb(n % 10);
        n /= 10;
    }
    reverse(nums.begin(), nums.end());
    int sz = nums.size();
    memset(dp, -1, sizeof(dp));
    return dfs(nums, 0, 0, 0, k, sz);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ten[0] = 1ll;
    for (int i = 1; i < 12; i++)
        ten[i] = ten[i - 1] * 10ll;
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}