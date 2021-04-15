#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll n, y;
    cin >> n >> y;
    ll ap = n * (2 + n - 1) / 2, sum=n;
    if (y < n || y > ap)
    {
        cout << "-1\n";
        return;
    }
    vector<ll> res(n, 1);
    set<ll> st;
    for (ll i = 2; i <= n; i++)
        st.insert(i);
    int cur = 0;
    while (sum < y)
    {
        ll mx = *st.rbegin();
        ll add = min(mx, y - sum + 1);
        st.erase(add);
        sum += add - 1;
        res[cur++] = add;
    }
    cur++;
    for (int i = cur; i < n; i++)
    {
        res[i] = *st.rbegin();
        st.erase(--st.end());
    }
    for (int r : res)
        cout << r << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}