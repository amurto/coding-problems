#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

ll solve()
{
    int n;
    ll len, w, res = 0;
    cin >> n >> len >> w;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<pii> seq;
    for (int i = 0; i < n;)
    {
        ll l = arr[i], r = arr[i] + w;
        int itr = i;
        while (itr < n && arr[itr] <= r)
        {
            r = arr[itr] + w;
            itr++;
        }
        seq.pb({l, r});
        i = itr;
    }
    ll cur = 0;
    int i = 0, sz = (int)seq.size();
    while (cur < len)
    {
        while (i < sz && seq[i].first <= cur)
        {
            cur = max(cur, seq[i].second);
            i++;
        }
        if (cur < len)
        {
            ll nxt = len;
            if (i < sz)
                nxt = seq[i].first;
            ll tarp = (nxt - cur + w - 1) / w;
            res += tarp;
            cur += w * tarp;
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