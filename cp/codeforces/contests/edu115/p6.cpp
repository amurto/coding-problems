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

class sequence
{
public:
    string str;
    vector<int> mns, rbs;
    int n, mn = 0, op = 0, suf = 0;
    sequence() {}
    sequence(string str) : str(str)
    {
        n = str.length();
        mns.resize(n);
        rbs.resize(n + 1);
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
                op++, cur++;
            else
                op--, cur--;
            if (cur < 0)
                mn--;
            mns[i] = mn;
            cur = max(0, cur);
        }
        for (int i = 0; i < n;)
        {
            int r = i, val = abs(mns[i]);
            while (i < n && mns[i] == mns[r])
                r++;
            int tot = 0, v = 0;
            if (val != 0)
                i++;
            while (i < r)
            {
                if (str[i] == '(')
                    v++;
                else
                    v--;
                tot += (v == 0);
                i++;
            }
            if (val != 0)
                tot++;
            rbs[val] = tot;
        }
    }
};

int solve()
{
    int n, res = 0;
    cin >> n;
    string str;
    vector<sequence> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        arr.pb(sequence(str));
    }
    vector<int> sum(1 << n), dp(1 << n, -1);
    dp[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int b = 0; b < n; b++)
            if ((mask >> b) & 1)
                sum[mask] = sum[mask ^ (1 << b)] + arr[b].op;
        for (int b = 0; b < n; b++)
        {
            if (((mask >> b) & 1) && dp[mask ^ (1 << b)] >= 0)
            {
                int tmp = sum[mask ^ (1 << b)] + arr[b].mn, prev_sum = sum[mask ^ (1 << b)];
                if (tmp >= 0)
                {
                    if (tmp == 0)
                        dp[mask] = max(dp[mask], dp[mask ^ (1 << b)] + arr[b].rbs[prev_sum]);
                    else
                        dp[mask] = max(dp[mask], dp[mask ^ (1 << b)]);
                } // bad rbs
                else
                    res = max(res, dp[mask ^ (1 << b)] + arr[b].rbs[prev_sum]);
            }
            res = max(res, dp[mask]);
        }
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