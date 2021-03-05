// https://codeforces.com/contest/955/problem/C
// Sad powers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll N = 1e6, LIM = 1e18;
set<ll> st;
vector<ll> arr;

void init()
{
    st.insert(1);
    for (ll i = 2; i <= N; i++)
    {
        ll cur = i * i * i;
        while (cur <= LIM)
        {
            st.insert(cur);
            if (cur > LIM / i)
                break;
            cur *= i;
        }
    }
    for (auto x : st)
    {
        ll sq = sqrt(x);
        if (sq * sq != x)
            arr.pb(x);
    }
}

ll sq_root(ll x)
{
    ll l = 0, r = 1e9 + 1;
    while (l != r)
    {
        ll mid = (l + r + 1) / 2;
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

ll query(ll b)
{
    if (b == 0)
        return 0;
    ll idx = upper_bound(arr.begin(), arr.end(), b) - arr.begin();
    return idx + sq_root(b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    ll l, r;
    int q;
    cin >> q;
    while (q-- > 0)
    {
        cin >> l >> r;
        cout << query(r) - query(l - 1) << "\n";
    }
    return 0;
}