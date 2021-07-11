#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];
int cnt[N], dp[N][2];
bool vis[N][2];
string ans[3] = {"Takahashi", "Aoki", "Draw"};
map<string, int> mp;
int id(string str)
{
    return mp[str];
}

int dfs(int cur, int p)
{
    if (dp[cur][p] == -1)
    {
        dp[cur][p] = 2;
        int res = p ^ 1;
        for (int e : g[cur])
        {
            int v = dfs(e, p ^ 1);
            if (v == p)
                res = p;
            else if (res != p && v == 2)
                res = 2;
        }
        dp[cur][p] = res;
    }
    return dp[cur][p];
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
    for (int i = 0; i < st.size(); i++)
        mp[st[i]] = i;
    int len = st.size();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < len; i++)
    {
        cnt[i] = 0;
        vis[i][0] = vis[i][1] = false;
    }
    for (int i = 0; i < n; i++)
    {
        int sz = arr[i].length();
        st.pb(arr[i].substr(0, 3));
        st.pb(arr[i].substr(sz - 3, 3));
        int i1 = id(l[i]), i2 = id(r[i]);
        g[i1].pb(i2);
        cnt[i1]++;
    }
    for (int i = 0; i < len; i++)
    {
        if (!g[i].empty())
        {
            sort(g[i].begin(), g[i].end());
            g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
        }
    }
    for (int i = 0; i < len; i++)
    {
        dfs(i, 0);
        dfs(i, 1);
    }
    for (int i = 0; i < n; i++)
    {
        int w = dfs(id(r[i]), 1);
        cout << ans[w] << "\n";
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