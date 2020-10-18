// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
// Subset Sum Problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Top Down Approach
// Recursion with Memo
// Time O(2^n) and Space O(n*sum)
int DP[101][10001];
int SSP(int N, int *arr, int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0 || N < 0)
        return 0;
    if (DP[N][sum] < 0)
        DP[N][sum] = max(SSP(N - 1, arr, sum - arr[N]), SSP(N - 1, arr, sum));
    return DP[N][sum];
}

int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 2 == 1)
        return 0;
    memset(DP, -1, sizeof(DP));
    return SSP(N - 1, arr, sum / 2);
}

// Bottom Up Approach
// Time O(n*subsetSum) and Space O(n*subsetSum)
bool canPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 2 == 1)
        return 0;
    int reqSum = sum / 2;
    int DP[N + 1][reqSum + 1];
    memset(DP, 0, sizeof(DP));
    DP[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= reqSum; j++)
        {
            if (DP[i - 1][j] || (j - arr[i - 1] >= 0 && DP[i - 1][j - arr[i - 1]]))
                DP[i][j] = 1;
            else
                DP[i][j] = 0;
        }
    }
    return DP[N][reqSum];
}

// Bottom Up Approach
// Optimized to 1D Array
// Time O(n*subsetSum) and Space O(subsetSum)
bool canPartition(int N, vector<int> &arr)
{
    int N=arr.size(), sum = 0;
    for (int v: arr)
        sum += v;
    if (sum % 2 == 1)
        return 0;
    sum/= 2;
    int DP[sum+1];
    memset(DP, 0, sizeof(DP));
    DP[0] = 1;
    for (int v: arr)
        for (int j = sum; j >= v; j--)
            DP[j] = DP[j] || DP[j-v];
    return DP[sum];
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cout << canPartition(N, arr) << endl;
    }
    return 0;
}