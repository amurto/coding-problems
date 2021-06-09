// https://codeforces.com/contest/1157/problem/F
// Maximum Balanced Circle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = *max_element(arr.begin(), arr.end());
    vector<int> cnt(mx + 1), dp(mx + 1), pre(mx + 1), suf(mx + 1);
    for (int i = 0; i < n; i++)
        cnt[arr[i]]++;
    for (int i = 1; i <= mx; i++)
        dp[i] = dp[i - 1] + cnt[i];
    int last = 1;
    for (int i = 1; i <= mx; i++)
    {
        if (cnt[i] > 0)
            pre[i] = last;
        if (cnt[i] == 0)
            last = i + 1;
        else if (cnt[i] == 1)
            last = i;
    }
    last = mx;
    for (int i = mx; i > 0; i--)
    {
        if (cnt[i] > 0)
            suf[i] = last;
        if (cnt[i] == 0)
            last = i - 1;
        else if (cnt[i] == 1)
            last = i;
    }
    int id = 1;
    vector<int> seq(mx + 1);
    for (int i = 1; i <= mx; i++)
    {
        if (cnt[i] > 0)
        {
            if (cnt[i] == 1)
                seq[i] = max(dp[i] - dp[pre[i] - 1], dp[suf[i]] - dp[i - 1]);
            else
                seq[i] = dp[i] - dp[pre[i] - 1] + dp[suf[i]] - dp[i - 1] - cnt[i];
        }
        if (seq[i] >= seq[id])
            id = i;
    }
    vector<int> res;
    if (cnt[id] == 1)
    {
        if (seq[id] = dp[id] - dp[pre[id] - 1])
        {
            for (int j = id; j >= pre[id]; j--)
            {
                res.pb(j);
                cnt[j]--;
            }
            for (int j = pre[id]; j <= id; j++)
            {
                while (cnt[j] > 0)
                {
                    res.pb(j);
                    cnt[j]--;
                }
            }
        }
        else
        {
            for (int j = id; j <= suf[id]; j++)
            {
                res.pb(j);
                cnt[j]--;
            }
            for (int j = suf[id]; j >= id; j--)
            {
                while (cnt[j] > 0)
                {
                    res.pb(j);
                    cnt[j]--;
                }
            }
            for (int j = id + 1; j <= suf[id]; j++)
            {
                res.pb(j);
                cnt[j]--;
            }
        }
    }
    else
    {
        for (int j = id; j >= pre[id]; j--)
        {
            res.pb(j);
            cnt[j]--;
        }
        for (int j = pre[id]; j <= id; j++)
        {
            while (cnt[j] > 0)
            {
                res.pb(j);
                cnt[j]--;
            }
        }
        for (int j = suf[id]; j >= id; j--)
        {
            while (cnt[j] > 0)
            {
                res.pb(j);
                cnt[j]--;
            }
        }
    }
    cout << res.size() << "\n";
    for (int r : res)
        cout << r << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}