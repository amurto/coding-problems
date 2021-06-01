#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool possible(vector<int> &arr, vector<int> &order, int n, int mid)
{
    int mn = order[0], mx = order[0];
    for (int i = 1; i < n; i++)
    {
        int cur = order[i];
        if (mid * 1ll * abs(mn - cur) > arr[cur])
            return false;
        if (mid * 1ll * abs(mx - cur) > arr[cur])
            return false;
        mn = min(mn, order[i]);
        mx = max(mx, order[i]);
    }
    return true;
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), order(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int &i1, int &i2)
         { return arr[i1] > arr[i2]; });
    int low = 0, high = 1e9, res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(arr, order, n, mid))
        {
            res = max(res, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
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