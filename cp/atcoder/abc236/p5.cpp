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

bool is_possible(vector<int> &arr, int mid, int n)
{
    vector<int> dp(n, -1e7);
    for (int i = 0; i < n; i++)
    {
        int prev1 = 0, prev2 = 0;
        if (i - 2 >= 0)
            prev1 = dp[i - 2];
        if (i - 1 >= 0)
            prev2 = dp[i - 1];
        if (arr[i] >= mid)
            dp[i] = max(dp[i], max(prev1, prev2) + 1);
        else
            dp[i] = max(dp[i], max(prev1, prev2) - 1);
    }
    return max(dp[n - 2], dp[n - 1]) >= 1;
}

int find_median(vector<int> &arr, int n)
{
    int low = 1, high = 1e9, res = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool pos = is_possible(arr, mid, n);
        if (pos)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}

double find_avg(vector<int> &seq, int n)
{
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = 1ll * seq[i] * 1000;
    ll low = 1, high = 1e12, res = 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        vector<ll> dp(n);
        dp[0] = arr[0] - mid;
        dp[1] = max(arr[0] + arr[1] - 2 * mid, arr[1] - mid);
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 2] + arr[i] - mid, dp[i - 1] + arr[i] - mid);
        if (max(dp[n - 2], dp[n - 1]) >= 0)
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return (1.0 * res) / (1.0 * 1000);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    double avg = find_avg(arr, n);
    int median = find_median(arr, n);
    cout << avg << "\n";
    cout << median << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    solve();
    return 0;
}