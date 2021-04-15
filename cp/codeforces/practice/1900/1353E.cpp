// https://codeforces.com/contest/1353/problem/E
// K-periodic Garland

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    vector<int> pre(n + 1);
    pre[0] = (str[0] == '1');
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + (str[i] == '1');
    int res = pre[n];
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        int last = (i - k >= 0) ? dp[i - k] : 0, ones = (i - k >= 0) ? pre[i - k] : 0, prev_ones = pre[i], suf = pre[n] - pre[i];
        if (str[i] == '1')
            prev_ones--;
        dp[i] = min(last + prev_ones - ones + (str[i] == '0'), prev_ones + (str[i] == '0'));
        res = min(res, min(pre[i], dp[i]) + suf);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}