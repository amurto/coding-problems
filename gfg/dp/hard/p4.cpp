#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Recursion with Memo
// Time O(n^2) and Space O(n)
int DP[1001][2];
int ZZSS(vector<int> &arr, int cur, int n, int flag)
{
    if (cur == n - 1)
        return 1;
    if (DP[cur][flag] < 0)
    {
        DP[cur][flag] = 1;
        if (flag == 0)
        {
            for (int i = cur + 1; i < n; i++)
                if (arr[i] > arr[cur])
                    DP[cur][flag] = max(DP[cur][flag], 1 + ZZSS(arr, i, n, 1));
        }
        else
        {
            for (int i = cur + 1; i < n; i++)
                if (arr[i] < arr[cur])
                    DP[cur][flag] = max(DP[cur][flag], 1 + ZZSS(arr, i, n, 0));
        }
    }
    return DP[cur][flag];
}

int ZigZag(vector<int> &arr, int n)
{
    memset(DP, -1, sizeof(DP));
    int MAX = 0;
    for (int i = 0; i < n; i++)
    {
        MAX = max(MAX, ZZSS(arr, i, n, 0));
        MAX = max(MAX, ZZSS(arr, i, n, 1));
    }
    return MAX;
}

int wiggleMaxLength(vector<int> &arr) {
    int n = arr.size();
    if (n<2)
        return n;
    int dp[n][2];
    dp[0][0] = dp[0][1] = 1;
    for (int i=1; i<n; i++) {
        if (arr[i-1] < arr[i]) {
            dp[i][1] = dp[i-1][0] + 1;
            dp[i][0] = dp[i-1][0];
        } else if (arr[i-1] > arr[i]) {
            dp[i][0] = dp[i-1][1] + 1;
            dp[i][1] = dp[i-1][1]; 
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1]; 
        }
    }
    return max(dp[n-1][0], dp[n-1][1]);
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }
    return 0;
}