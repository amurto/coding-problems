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
typedef pair<pair<int, int>, int> piii;
#define pb push_back

const int N = 1e5 + 5;
vector<int> dvs[N];
int last[N];

void init()
{
    last[1] = -1;
    for (int i = 2; i < N; i++)
    {
        last[i] = -1;
        for (int j = i; j < N; j += i)
            dvs[j].pb(i);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n), L(q), R(q), res(q);
    vector<vector<int>> queries(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < q; i++)
    {
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
        queries[R[i]].pb(i);
    }
    set<pii> st;
    st.insert({-1, N});
    for (int i = 0; i < n; i++)
    {
        for (int dv : dvs[arr[i]])
        {
            if (last[dv] != -1)
            {
                // s.pupd(last[dv], last[dv], dv);
                auto it = st.upper_bound(pii(last[dv], dv));
                if (it == st.end() || it->second < dv)
                {
                    it--;
                    vector<pii> del;
                    while (it->first != -1 && it->second <= dv)
                    {
                        del.pb(*it);
                        it--;
                    }
                    for (pii de : del)
                        st.erase(de);
                    st.insert({last[dv], dv});
                }
            }
        }
        for (int id : queries[i])
        {
            auto it = st.lower_bound(pii(L[id], 0));
            if (it == st.end())
                res[id] = 1;
            else
                res[id] = max(1, it->second);
        }
        for (int dv : dvs[arr[i]])
            last[dv] = i;
    }
    for (int i = 0; i < q; i++)
        cout << res[i] << "\n";
    for (int i = 0; i < n; i++)
        for (int dv : dvs[arr[i]])
            last[dv] = -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}