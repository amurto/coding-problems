#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

const ll inf = 2e18 + 5;
set<pii> st;

ll remove_skill(ll x)
{
    ll pos = 0;
    pii p = {x, 0};
    auto lb = st.lower_bound(p);
    lb--;
    auto rb = st.lower_bound(p);
    ll l1 = lb->first, r1 = lb->second, l2 = rb->first, r2 = rb->second;
    if (l1 <= x && x <= r1)
    {
        pos = x;
        st.erase(lb);
        if (l1 <= x - 1)
            st.insert({l1, x - 1});
        if (x + 1 <= r1)
            st.insert({x + 1, r1});
    }
    else if (l2 <= x && r2 <= x)
    {
        pos = x;
        st.erase(rb);
        if (l2 <= x - 1)
            st.insert({l2, x - 1});
        if (x + 1 <= r2)
            st.insert({x + 1, r2});
    }
    else
    {
        ll d1 = x - r1, d2 = l2 - x;
        if (d1 <= d2)
        {
            st.erase(lb);
            pos = r1;
            if (r1 - 1 >= l1)
                st.insert({l1, r1 - 1});
        }
        else
        {
            st.erase(rb);
            pos = l2;
            if (l2 + 1 <= r2)
                st.insert({l2 + 1, r2});
        }
    }
    return pos;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    st.clear();
    st.insert({-inf, -inf});
    st.insert({inf, inf});
    vector<pii> arr(n);
    vector<ll> skill(m), res(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        st.insert({arr[i].first, arr[i].second});
    }
    for (int i = 0; i < m; i++)
        cin >> skill[i];
    for (int i = 0; i < m; i++)
        res[i] = remove_skill(skill[i]);
    for (int i = 0; i < m; i++)
        cout << res[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}