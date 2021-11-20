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
    int q;
    cin >> q;
    int n = (1 << 20);
    set<int> st;
    vector<ll> arr(n, -1);
    for (int i = 0; i < n; i++)
        st.insert(i);
    for (int i = 0; i < q; i++)
    {
        int t;
        ll x;
        cin >> t >> x;
        ll id = x % n;
        if (t == 1)
        {
            if (st.lower_bound(id) == st.end())
                id = 0;
            auto it = st.lower_bound(id);
            arr[*it] = x;
            st.erase(it);
        }
        else
            cout << arr[id] << "\n";
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