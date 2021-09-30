#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Fastest approach
// O(nlogn)
// DP + Binary Search
// https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
int LIS(vector<int> &arr, int n)
{
    vector<int> small(n + 1, n), dp(n);

    // small[i] -> lis of length i ends at small[i]
    // small[i] is minimum possible
    // small is always sorted
    // dp[i] -> length of lis ending at i
    small[0] = -1;
    for (int i = 0; i < n; i++)
    {
        int low = 0, high = n - 1, v = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (small[mid] < arr[i])
            {
                v = max(v, mid);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        dp[i] = v + 1;
        small[v + 1] = arr[i];
    }
    return *max_element(dp.begin(), dp.end());
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return LIS(arr, n);
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