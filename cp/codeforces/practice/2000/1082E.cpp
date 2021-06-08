// https://codeforces.com/contest/1082/problem/E
// Increasing Frequency

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, c;
    cin >> n >> c;
    map<int, int> last;
    vector<int> arr(n + 1), cnt(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        cnt[i] += cnt[i - 1] + (arr[i] == c);
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1 + max(cnt[i - 1], dp[last[arr[i]]]);
        last[arr[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        dp[i] += cnt[n] - cnt[i];
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}