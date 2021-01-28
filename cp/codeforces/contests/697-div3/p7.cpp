#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    set<int> st(arr.begin(), arr.end());
    int mx = *st.rbegin(), res = 0;
    vector<int> cnt(mx + 1), dp(mx + 1);
    for (int e : arr)
        cnt[e]++;
    for (int e : st)
    {
        dp[e] += cnt[e];
        for (int i = 2 * e; i <= mx; i += e)
            dp[i] = max(dp[i], dp[e]);
        res = max(res, dp[e]);
    }
    return n - res;
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