#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int moves(vector<ll> &pre, vector<ll> &suf, int n, ll l, ll r, ll target)
{
    int low = 0, high = n - 1, res = n - 1, diff = abs(target - pre[n - 1]);
    if (pre[n - 1] == target)
        return 0;
    if (pre[n - 1] > target)
    {
        // decrease sum
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int mn = l * (mid + 1);
            if (suf[mid] - mn >= diff)
            {
                res = min(res, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
    }
    else
    {
        // increase sum
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            ll mx = r * (mid + 1);
            if (mx - pre[mid] >= diff)
            {
                res = min(res, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
    }
    return res + 1;
}

int solve()
{
    int k, n;
    ll l, r;
    cin >> k >> n >> l >> r;
    vector<vector<ll>> arr(k, vector<ll>(n)), pre(k, vector<ll>(n)), suf(k, vector<ll>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
        sort(arr[i].begin(), arr[i].end());
        pre[i][0] = arr[i][0];
        for (int j = 1; j < n; j++)
            pre[i][j] = pre[i][j - 1] + arr[i][j];
        reverse(arr[i].begin(), arr[i].end());
        suf[i][0] = arr[i][0];
        for (int j = 1; j < n; j++)
            suf[i][j] = suf[i][j - 1] + arr[i][j];
    }
    ll low = l * n, high = r * n;
    int res = n * k;
    while (low <= high)
    {
        ll mid1 = low + (high - low) / 3;
        ll mid2 = high - (high - low) / 3;
        int m1 = 0, m2 = 0;
        for (int i = 0; i < k; i++)
            m1 = max(m1, moves(pre[i], suf[i], n, l, r, mid1));
        for (int i = 0; i < k; i++)
            m2 = max(m2, moves(pre[i], suf[i], n, l, r, mid2));
        res = min(res, min(m1, m2));
        if (m1 >= m2)
            low = mid1 + 1;
        else
            high = mid2 - 1;
    }
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