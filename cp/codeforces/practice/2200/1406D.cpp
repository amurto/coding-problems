// https://codeforces.com/contest/1406/problem/D
// Three Sequences

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

void upd(vector<ll> &diff, int id, ll x, ll &neg_sum, ll &pos_sum)
{
    if (diff[id] < 0)
        neg_sum -= diff[id];
    else
        pos_sum -= diff[id];
    diff[id] += x;
    if (diff[id] < 0)
        neg_sum += diff[id];
    else
        pos_sum += diff[id];
}

ll find_mx(ll f, ll a, ll neg_sum, ll pos_sum)
{
    return max(f, a - f + pos_sum);
}

ll calc(ll a, ll neg_sum, ll pos_sum)
{
    ll low = -1e18, high = 1e18;
    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        bool pos = false;
        if (find_mx(mid, a, neg_sum, pos_sum) <= mid || find_mx(a - (mid - pos_sum), a, neg_sum, pos_sum) <= mid)
            pos = true;
        if (pos)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

void solve()
{
    int n, q;
    cin >> n;
    vector<ll> arr(n), diff(n);
    ll neg_sum = 0, pos_sum = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
    {
        diff[i - 1] = arr[i] - arr[i - 1];
        if (diff[i - 1] < 0)
            neg_sum += diff[i - 1];
        else
            pos_sum += diff[i - 1];
    }
    cin >> q;
    cout << calc(arr[0], neg_sum, pos_sum) << "\n";
    for (int i = 0; i < q; i++)
    {
        int l, r;
        ll x;
        cin >> l >> r >> x;
        l--;
        r--;
        if (l == 0)
            arr[0] += x;
        if (l > 0)
            upd(diff, l - 1, x, neg_sum, pos_sum);
        if (r < n - 1)
            upd(diff, r, -x, neg_sum, pos_sum);
        cout << calc(arr[0], neg_sum, pos_sum) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}