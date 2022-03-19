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

ll solve()
{
    ll n, k, res = 0;
    cin >> n >> k;
    vector<ll> arr(n), nxt(n), vis(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        nxt[i] = (i + arr[i]) % n;
    }
    ll cur = 0, t = 0;
    while (vis[cur] == -1)
    {
        res += arr[cur];
        k--;
        if (k == 0)
            return res;
        vis[cur] = t;
        cur = nxt[cur];
        t++;
    }
    ll len = t - vis[cur];
    vector<ll> pre(len);
    pre[0] = arr[cur];
    for (int i = 1; i < len; i++)
    {
        cur = nxt[cur];
        pre[i] = pre[i - 1] + arr[cur];
    }
    res += ((k / len) * pre[len - 1]);
    k %= len;
    if (k > 0)
        res += pre[k - 1];
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