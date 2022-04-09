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

void solve()
{
    int n, k = 0;
    cin >> n;
    vector<int> arr(n), ids(n), vis(n, 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return arr[i1] > arr[i2]; });
    ll sum = 0;
    for (int i = 0; i < n / 2; i++)
    {
        sum += 1ll * arr[ids[i]];
        vis[ids[i]] = -1;
    }
    int val = 0;
    vector<int> pre(n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            pre[i] = pre[i - 1];
            if (val < 0)
                pre[i] = max(pre[i], abs(val));
        }
        val += vis[i];
    }
    if (pre[n - 1] != 0)
    {
        int suf_mn = 1e9 + 7, suf_sum = 0;
        for (int i = n - 1; i > 0; i--)
        {
            suf_sum += vis[i];
            suf_mn = min(vis[i], vis[i] + suf_mn);
            if (suf_sum >= pre[i - 1] && suf_mn >= 0)
                k = i;
        }
    }
    cout << k << " " << sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}