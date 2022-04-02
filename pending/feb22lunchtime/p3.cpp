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
    int n, q;
    string str;
    cin >> n >> q >> str;
    set<int> st;
    st.insert(-1);
    st.insert(n);
    st.insert(n + 1);
    for (int i = 1; i < n; i++)
        if (str[i - 1] != str[i])
            st.insert(i - 1);
    for (int i = 0; i < q; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        if (t == 1)
        {

            if (l > 0)
            {
                if (st.find(l - 1) != st.end())
                    st.erase(l - 1);
                else
                    st.insert(l - 1);
            }
            if (r < n - 1)
            {
                if (st.find(r) != st.end())
                    st.erase(r);
                else
                    st.insert(r);
            }
        }
        else
        {
            int x;
            cin >> x;
            x--;
            auto it = st.lower_bound(x);
            int cur = *it;
            it--;
            int prev = *it;
            bool ans = true;
            if (prev < l && cur + 1 > r)
                ans = (l == x);
            else
            {
                it++;
                it++;
                int nxt = *it;
                if (prev < l && nxt >= r)
                        ans = false;
            }
            ans ? cout << "YES\n" : cout << "NO\n";
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
