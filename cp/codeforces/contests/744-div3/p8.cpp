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

bool pos(vector<int> &arr, int l, int r, int n)
{
    int cur = arr[0];
    if (r < cur)
        return false;
    for (int i = 1; i < n; i++)
    {
        d(cur);
        int d1 = abs(cur - l), d2 = abs(r - cur);
        if (max(d1, d2) < arr[i])
            return false;
        d(d1, d2);
        if (d1 < d2)
        {
            if (d1 >= arr[i])
                cur -= arr[i];
            else
                cur += arr[i];
        }
        else
        {
            if (d2 >= arr[i])
                cur += arr[i];
            else
                cur -= arr[i];
        }
    }
    d(cur);
    return true;
}

int solve()
{
    int n, mx = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    int res = 2 * mx + 5;
    cout << pos(arr, -2, 10, n) << "\n";
    // for (int l = -2; l <= -2; l++)
    // {
    //     int low = arr[0], high = max(l + 2 * mx, arr[0]), r = max(arr[0], l + 2 * mx);
    //     while (low <= high)
    //     {
    //         int mid = low + (high - low) / 2;
    //         d(low,high);
    //         if (pos(arr, l, mid, n))
    //         {
    //             r = min(r, mid);
    //             high = mid - 1;
    //         }
    //         else
    //             low = mid + 1;
    //     }
    //     d(l, r);
    //     res = min(res, r - l);
    // }
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