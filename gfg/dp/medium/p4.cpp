// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem/0
// The Painter's Partition Problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[31][51];

// DP Approach O(k*n)
int MinimumTime(int *a, int k, int n)
{
    if (n < 0)
        return 0;
    if (DP[k][n] < 0)
    {
        int sum = 0;
        for (int i = n; i >= 0; i--)
        {
            sum += a[i];
            if (DP[k][n] == -1)
                DP[k][n] = max(sum, MinimumTime(a, k - 1, i - 1));
            else
                DP[k][n] = min(DP[k][n], max(sum, MinimumTime(a, k - 1, i - 1)));
        }
    }
    return DP[k][n];
}

// Return Maximum Element
int MAX(int *a, int n)
{
    int m = -1;
    for (int i = 0; i < n; i++)
        m = max(m, a[i]);
    return m;
}

// Return sum of all elements
int SUM(int *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

// Return number of painters required with current mid
int Painters(int *a, int n, int mid)
{
    int sum = 0, c = 1;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > mid)
        {
            sum = a[i];
            c++;
        }
    }
    return c;
}

// Binary Search Approach O(nlogn)
// only works if array is sorted
int PPP(int *a, int n, int k)
{
    int low = MAX(a, n), high = SUM(a, n);
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        cout<<"mid: "<<mid<<endl;
        int c = Painters(a, n, mid);
        if (c <= k)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int k, n;
        cin >> k >> n;
        int a[n], sum = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // memset(DP, -1, sizeof(DP));
        // for (int i = 0; i < n; i++)
        // {
        //     sum += a[i];
        //     DP[1][i] = sum;
        // }
        // cout << MinimumTime(a, k, n - 1) << endl;
        cout << PPP(a, n, k) << endl;
    }
    return 0;
}