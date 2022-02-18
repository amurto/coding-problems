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

// Fastest approach
// O(nlogn)
// DP + Binary Search
// https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
int LIS(vector<int> &arr, int n)
{
    vector<int> small(n + 1, 1e9 + 7), dp(n);

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
            if (small[mid] <= arr[i])
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
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    int lis_a = LIS(A, n), lis_b = LIS(B, m);
    res = lis_a + lis_b;
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