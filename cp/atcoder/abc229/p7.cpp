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

bool calc(vector<ll> &ids, int x, int n, ll k)
{
    vector<ll> pre(n);
    pre[0] = ids[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + ids[i];
    for (int l = 0, r = x - 1; r < n; l++, r++)
    {
        int mid = l + (r - l) / 2;
        ll l_sum = pre[mid], r_sum = pre[r] - pre[mid];
        if (l > 0)
            l_sum -= pre[l - 1];
        ll mx = (ids[mid] * (2ll * mid + 1 - l - r)) - l_sum + r_sum;
        if (mx <= k)
            return true;
    }
    return false;
}

int solve()
{
    string str;
    ll k;
    cin >> str >> k;
    vector<ll> ids;
    for (int i = 0; i < (int)str.length(); i++)
        if (str[i] == 'Y')
            ids.pb(i);
    if (ids.empty())
        return 0;
    int sz = (int)ids.size();
    for (int i = 0; i < sz; i++)
        ids[i] -= i;
    int low = 1, high = sz, res = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (calc(ids, mid, sz, k))
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