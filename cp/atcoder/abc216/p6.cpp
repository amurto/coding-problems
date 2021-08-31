#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first;
    for (int i = 0; i < n; i++)
        cin >> arr[i].second;
    sort(arr.begin(), arr.end());
    int mx = arr[n - 1].first;
    vector<int> dp(mx + 1), sdp(mx + 1);
    dp[0] = sdp[0] = 1;
    for (pii p : arr)
    {
        int l = p.first, r = p.second;
        for (int j = l; j >= r; j--)
            dp[j] = add(dp[j], sdp[j - r]);
        for (int j = mx; j >= r; j--)
            sdp[j] = add(sdp[j], sdp[j - r]);
    }
    for (int i = 1; i <= mx; i++)
        res = add(res, dp[i]);
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