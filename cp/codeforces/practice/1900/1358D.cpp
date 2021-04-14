// https://codeforces.com/contest/1358/problem/D
// The Best Vacation

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll ap(ll a, ll d, ll n)
{
    return (n * (2 * a + (n - 1) * d)) / 2;
}

ll solve()
{
    int n;
    ll x, res = 0;
    cin >> n >> x;
    vector<ll> tmp(n), arr;
    for (int i = 0; i < n; i++)
        cin >> tmp[i];
    arr.pb(0);
    for (int j = 0; j < 3; j++)
        for (int i = 0; i < n; i++)
            arr.pb(tmp[i]);
    arr.pb(0);
    int sz = arr.size();
    vector<ll> pre(sz), presum(sz);
    for (int i = 1; i < sz; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
        presum[i] = presum[i - 1] + ap(1, 1, arr[i]);
    }
    for (int i = 1 + n; i <= 2 * n; i++)
    {
        if (x > arr[i])
        {
            // left
            int l = 1, r = i, idx = i;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (pre[i] - pre[mid - 1] <= x)
                {
                    idx = min(idx, mid);
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            ll sum = presum[i] - presum[idx - 1];
            if (pre[i] - pre[idx - 1] < x)
                sum += ap(1, 1, arr[idx - 1]) - ap(1, 1, arr[idx - 1] - x + pre[i] - pre[idx - 1]);
            res = max(res, sum);
            
            // right
            l = i, r = sz - 1, idx = i;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (pre[mid] - pre[i - 1] <= x)
                {
                    idx = max(idx, mid);
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            sum = presum[idx] - presum[i - 1];
            if (pre[idx] - pre[i - 1] < x)
                sum += ap(1, 1, arr[idx + 1]) - ap(1, 1, arr[idx + 1] - x + pre[idx] - pre[i - 1]);
            res = max(res, sum);
        }
        else
            res = max(res, ap(1, 1, arr[i]) - ap(1, 1, arr[i] - x));
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