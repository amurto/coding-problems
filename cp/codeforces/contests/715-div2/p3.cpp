#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e3 + 5;
ll dp[N][N];

ll sports(vector<ll> &arr, int l, int r, int n)
{
    if (l == 0 && r == n - 1)
        return 0;
    if (dp[l][r] == -1)
    {
        ll res = 0, mn = arr[l], mx = arr[r];
        if (l == 0)
            res = arr[r + 1] - mn + sports(arr, l, r + 1, n);
        else if (r == n - 1)
            res = mx - arr[l - 1] + sports(arr, l - 1, r, n);
        else
            res = min(mx - arr[l - 1] + sports(arr, l - 1, r, n), arr[r + 1] - mn + sports(arr, l, r + 1, n));
        dp[l][r] = res;
    }
    return dp[l][r];
}
ll solve()
{
    int n;
    ll res = 1e18;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
        res = min(res, sports(arr, i, i, n));
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