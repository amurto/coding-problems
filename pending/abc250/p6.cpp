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

const ll inf = 2e18;
ll polygonArea(vector<ll> &X, vector<ll> &Y, int n)
{
    ll area = 0; // Accumulates area
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i; // j is previous vertex to i
    }
    return area;
}

ll solve()
{
    int n;
    cin >> n;
    ll res = LLONG_MAX;
    vector<ll> X(n), Y(n);
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());
    ll area = polygonArea(X, Y, n);

    vector<ll> pre(n);
    for (int j = 0; j < n; j++)
    {
        int i = (j + 1) % n;
        pre[j] = (X[j] + X[i]) * (Y[j] - Y[i]);
        if (j > 0)
            pre[j] += pre[j - 1];
    }
    auto get_range_sum = [&](int l, int r) -> ll
    {
        ll ans = pre[r];
        if (l > 0)
            ans -= pre[l - 1];
        return ans;
    };
    for (int j = 0; j < n; j++)
    {
        int low = 2, high = n - 2;
        ll cur = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int i = (j + mid) % n;
            ll val = area;
            if (i < j)
            {
                val -= get_range_sum(j, n - 1);
                val -= get_range_sum(0, i - 1);
            }
            else
            {
                val -= get_range_sum(j, i - 1);
            }
            val += (X[j] + X[i]) * (Y[j] - Y[i]);
            if (area - 4 * val >= 0)
            {
                cur = max(cur, val);
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (cur > 0)
        {
            res = min(res, abs(area - 4 * cur));
            res = min(res, abs(area - 4 * (area - cur)));
        }
    }
    for (int j = 0; j < n; j++)
    {
        int low = 2, high = n - 2;
        ll cur = inf;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int i = (j + mid) % n;
            ll val = area;
            if (i < j)
            {
                val -= get_range_sum(j, n - 1);
                val -= get_range_sum(0, i - 1);
            }
            else
            {
                val -= get_range_sum(j, i - 1);
            }
            val += (X[j] + X[i]) * (Y[j] - Y[i]);
            if (area - 4 * val < 0)
            {
                cur = min(cur, val);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if (cur < inf)
        {
            res = min(res, abs(area - 4 * cur));
            res = min(res, abs(area - 4 * (area - cur)));
        }
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