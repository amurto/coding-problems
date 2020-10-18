// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
// Minimum sum partition

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int minDifference(int arr[], int n)
{
    int sum = 0, ans = INT_MAX, p;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    vector<bool> DP(sum + 1, false);
    DP[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >=0; j--)
        {
            if (DP[j])
            {
                DP[j + arr[i]] = true;
                p = j + arr[i];
                ans = min(ans, abs(p - (sum - p)));
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << minDifference(arr, n) << "\n";
    }
    return 0;
}