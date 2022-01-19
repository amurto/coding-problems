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

ll ap(ll a, ll diff, ll n)
{
    return (n * (a * 2 + (n - 1) * diff)) / 2;
}

bool is_intersect(ll l1, ll r1, ll l2, ll r2)
{
    if (r1 > r2)
    {
        swap(l1, l2);
        swap(r1, r2);
    }
    return l2 <= r1;
}

int solve()
{
    int n, res = 0;
    ll a, b;
    cin >> n >> a >> b;
    ll t = b - a + 1;
    vector<ll> pts;
    map<ll, int> mp;
    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        mp[l]++;
        mp[r + 1]--;
        pts.pb(l);
        pts.pb(r + 1);
    }
    sort(pts.begin(), pts.end());
    pts.pb(pts.back() + 1);
    pts.resize(unique(pts.begin(), pts.end()) - pts.begin());
    int itr = 0, cur = 0;
    for (auto v : mp)
    {
        cur += v.second;
        ll l = v.first, r = pts[itr + 1] - 1;
        ll low = 1, high = t, pos = 0;
        while (low <= high)
        {
            ll mid = low + (high - low) / 2;
            ll l_pt = (a - 1) * mid + ap(1, 1, mid), r_pt = (a - 1) * mid + ap(t, -1, mid);
            if (is_intersect(l, r, l_pt, r_pt))
            {
                pos = 1;
                low = high + 1;
            }
            else
            {
                if (r_pt < l)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        if (pos)
            res = max(res, cur);
        itr++;
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