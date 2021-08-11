// https://codeforces.com/contest/1355/problem/E
// Restorer Distance

#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll find_cost(vector<ll> &arr, ll cur, ll add, ll rem, ll m, int n)
{
    ll pre = 0, suf = 0, l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < cur)
        {
            pre += arr[i];
            l++;
        }
        else
        {
            suf += arr[i];
            r++;
        }
    }
    ll preB = cur * l - pre;
    ll sufB = suf - cur * r;
    ll mn = min(preB, sufB);
    ll cost = mn * m;
    preB -= mn;
    sufB -= mn;
    if (preB > sufB)
        cost += add * preB;
    else
        cost += rem * sufB;
    return cost;
}

ll solve()
{
    int n;
    ll add, rem, m, sum = 0, pre = 0;
    cin >> n >> add >> rem >> m;
    m = min(m, add + rem);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ll low = 0, high = 1e9, res = 1e18;
    while (high - low > 1)
    {
        ll mid = low + (high - low) / 2;
        ll v1 = find_cost(arr, mid, add, rem, m, n), v2 = find_cost(arr, mid + 1, add, rem, m, n);
        if (v1 > v2)
            low = mid;
        else
            high = mid;
    }
    res = min(res, find_cost(arr, low + 1, add, rem, m, n));
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