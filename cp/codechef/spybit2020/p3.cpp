#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q, x;
    ll k;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(i);
    cin >> q;
    while (q-- > 0)
    {
        cin >> x >> k;
        x--;
        auto it = st.lower_bound(x);
        if (it == st.end())
            cout << "0\n";
        else
        {
            ll dis = 0;
            vector<int> e;
            for (auto cur = it; k > 0 && cur != st.end(); cur++)
            {
                int id = *cur;
                if (arr[id] < k)
                {
                    dis += arr[id] * (id - x);
                    k -= arr[id];
                    arr[id] = 0;
                    e.pb(id);
                }
                else
                {
                    dis += k * (id - x);
                    arr[id] -= k;
                    k = 0;
                }
            }
            for (int id : e)
                st.erase(id);
            cout << dis << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}