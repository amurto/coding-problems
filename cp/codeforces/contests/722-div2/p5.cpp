#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int N = 3e5 + 5;
vector<int> g1[N], g2[N];
int vis1[N], vis2[N];

int precompute(int cur, int last, int t)
{
    vis1[cur] = vis2[cur] = t;
    for (int e : g2[cur])
        if (e != last)
            vis2[cur] = precompute(e, cur, vis2[cur] + 1);
    return vis2[cur];
}

int dfs(set<pii> &st, int cur, int last)
{
    pii v = {vis1[cur], cur}, del = {-1, -1};
    bool d = false, u = true;
    if (st.empty())
        st.insert(v);
    else
    {
        auto it = st.upper_bound(v);
        if (it != st.end())
            if (vis2[it->second] <= vis2[cur])
                u = false;
        if (u)
        {
            if (it != st.begin())
            {
                it--;
                if (vis2[it->second] >= vis2[cur])
                {
                    del = *it;
                    st.erase(it);
                    d = true;
                }
            }
            st.insert(v);
        }
    }
    int res = (int)st.size();
    for (int e : g1[cur])
        if (e != last)
            res = max(res, dfs(st, e, cur));
    st.erase(v);
    if (d)
        st.insert(del);
    return res;
}

int solve()
{
    int n, p;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g1[i].clear();
        g2[i].clear();
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        g1[i].pb(p);
        g1[p].pb(i);
    }
    for (int i = 2; i <= n; i++)
    {
        cin >> p;
        g2[i].pb(p);
        g2[p].pb(i);
    }
    precompute(1, 1, 0);
    set<pii> st;
    return dfs(st, 1, 1);
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