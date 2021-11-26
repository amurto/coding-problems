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
    vector<int> small(n + 1, 205), dp(n);

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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    vector<int> seq;
    for (int i = 0; i < k; i++)
        seq.pb(arr[i]);
    int len = k;
    for (int i = k; i < n; i++)
    {
        int f = -1;
        vector<int> nseq;
        for (int j = 0; j <= len; j++)
        {
            vector<int> tmp = seq;
            if (j == len)
                tmp.pb(arr[i]);
            else
                tmp.insert(tmp.begin() + j, arr[i]);
            int lis = LIS(tmp, len + 1);
            if (lis == k)
            {
                if (f == -1 || tmp < nseq)
                {
                    f = 1;
                    swap(nseq, tmp);
                }
            }
        }
        if (f == -1)
        {
            cout << "-1\n";
            return;
        }
        swap(seq, nseq);
        len++;
    }
    for (int x : seq)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}