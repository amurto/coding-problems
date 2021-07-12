#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N], gt[N];
int deg[N];
bool vis[N], win[N], lose[N];

void dfs(int cur)
{
    vis[cur] = true;
    for (int e : gt[cur])
    {
        if (!vis[e])
        {
            if (lose[cur])
                win[e] = true;
            else if (--deg[e] == 0)
                lose[e] = true;
            else
                continue;
            dfs(e);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<string> arr(n), l(n), r(n), st;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int sz = arr[i].length();
        l[i] = arr[i].substr(0, 3);
        r[i] = arr[i].substr(sz - 3, 3);
        st.pb(l[i]);
        st.pb(r[i]);
    }
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
    map<string, int> mp;
    for (int i = 0; i < st.size(); i++)
        mp[st[i]] = i;
    int len = st.size();
    for (int i = 0; i < n; i++)
    {
        int sz = arr[i].length();
        st.pb(arr[i].substr(0, 3));
        st.pb(arr[i].substr(sz - 3, 3));
        int i1 = mp[l[i]], i2 = mp[r[i]];
        g[i1].pb(i2);
    }
    for (int i = 0; i < len; i++)
    {
        if (!g[i].empty())
        {
            sort(g[i].begin(), g[i].end());
            g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
        }
    }
    vector<int> nodes;
    for (int i = 0; i < len; i++)
    {
        vis[i] = win[i] = lose[i] = false;
        for (int e : g[i])
            gt[e].pb(i);
        if (g[i].empty())
        {
            lose[i] = 1;
            nodes.pb(i);
        }
    }
    for (int i = 0; i < len; i++)
        deg[i] = (int)g[i].size();
    for (int x : nodes)
        if (!vis[x])
            dfs(x);
    for (int i = 0; i < n; i++)
    {
        int id = mp[r[i]];
        if (win[id])
            cout << "Aoki\n";
        else if (lose[id])
            cout << "Takahashi\n";
        else
            cout << "Draw\n";
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