// https://codeforces.com/contest/1167/problem/E
// Range Deleting

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e8 + 5;
ll solve()
{
    int n, x;
    ll ans = 0;
    cin >> n >> x;
    vector<int> arr(n), mnv(x + 1, inf), mxv(x + 1, -1);
    // mnv[e] is minimum value after e
    // mxv[e] is maximum value before e
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mx = 0, mn = inf;
    for (int i = 0; i < n; i++)
    {
        mxv[arr[i]] = max(mxv[arr[i]], mx);
        mx = max(mx, arr[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        mnv[arr[i]] = min(mnv[arr[i]], mn);
        mn = min(mn, arr[i]);
    }
    vector<int> suf(x + 2, inf);
    for (int i = x; i > 0; i--)
        suf[i] = min(mnv[i], suf[i + 1]);
    vector<int> begsort(x + 2), revsort(x + 2);
    begsort[0] = 1;
    for (int i = 1; i <= x; i++)
        begsort[i] = begsort[i - 1] & (mnv[i] >= i);
    revsort[x + 1] = 1;
    for (int i = x; i > 0; i--)
        revsort[i] = revsort[i + 1] & (mxv[i] <= i);
    for (int i = 1; begsort[i - 1] && i <= x; i++)
    {
        int low = i, high = x, res = x + 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (revsort[mid + 1] && suf[mid + 1] >= i)
            {
                res = min(res, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if (res != x + 1)
            ans += 1ll * (x - res + 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}