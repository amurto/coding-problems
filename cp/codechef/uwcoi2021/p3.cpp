#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> c(n + 1);
        set<pair<ll, ll>> st;
        for (ll i = 0; i <= n; i++)
        {
            cin >> c[i];
            st.insert({c[i], i});
        }
        while (!st.empty())
        {
            ll d1 = st.begin()->first, c1 = st.begin()->second;
            st.erase(st.begin());
            if (d1 == k)
            {
                cout << c1 << " " << d1 << " " << 0 << " " << 0 << "\n";
            }
            else
            {
                auto it = st.end();
                it--;
                ll d2 = it->first, c2 = it->second;
                st.erase(it);
                d2 = d2 - (k - d1);
                if (d2 > 0)
                    st.insert({d2, c2});
                cout << c1 << " " << d1 << " " << c2 << " " << k - d1 << "\n";
            }
        }
    }
    return 0;
}