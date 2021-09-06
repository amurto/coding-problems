#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, q;
    cin >> n >> q;
    set<pii> st;
    st.insert({0, n});
    for (int i = 0; i < q; i++)
    {
        int c, x;
        cin >> c >> x;
        if (c == 1)
        {
            pii p = {x, x};
            auto it = st.upper_bound(p);
            it--;
            pii cur = *it;
            st.erase(it);
            st.insert({cur.first, x});
            st.insert({x, cur.second});
        }
        else
        {
            pii p = {x, x};
            auto it = st.upper_bound(p);
            it--;
            pii cur = *it;
            int ans = cur.second - cur.first;
            cout << ans << "\n";
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