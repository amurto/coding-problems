#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e9 + 7;

bool pos(string &str, int n, int k, int w)
{
    vector<vector<int>> pre(n, vector<int>(k + 1)), mn(n, vector<int>(k, inf));
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            pre[i] = pre[i - 1];
        if (str[i] == '?')
            pre[i][k]++;
        else
            pre[i][str[i] - 'a']++;
    }
    for (int i = w - 1; i < n; i++)
    {
        int q = pre[i][k];
        if (i - w >= 0)
            q -= pre[i - w][k];
        for (int j = 0; j < k; j++)
        {
            int c = pre[i][j];
            if (i - w >= 0)
                c -= pre[i - w][j];
            if (q + c >= w)
                mn[i - w + 1][j] = i + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j < k; j++)
            mn[i][j] = min(mn[i][j], mn[i + 1][j]);
    vector<int> dp(1 << k, inf);
    dp[0] = 0;
    for (int i = 1; i < (1 << k); i++)
        for (int b = 0; b < k; b++)
            if (((i >> b) & 1) && dp[i ^ (1 << b)] < n)
                dp[i] = min(dp[i], mn[dp[i ^ (1 << b)]][b]);
    return (dp[(1 << k) - 1] <= n);
}

int solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    int low = 1, high = n, res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (pos(str, n, k, mid))
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
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