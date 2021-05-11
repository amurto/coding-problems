// https://codeforces.com/contest/1370/problem/D
// Odd-Even Subsequence

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int jump(vector<int> &arr, int x, int p)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((j + 1) % 2 == p)
        {
            if (arr[i] <= x)
                j++;
        }
        else
            j++;
    }
    return j;
}

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low = 1, high = 1e9, res = 1e9;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (jump(arr, mid, 1) >= k || jump(arr, mid, 0) >= k)
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
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