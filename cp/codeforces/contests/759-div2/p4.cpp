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

int dfs(vector<int> &p, vector<bool> &vis, int cur)
{
    int cnt = 1;
    vis[cur] = true;
    if (!vis[p[cur]])
        cnt += dfs(p, vis, p[cur]);
    return cnt;
}

bool solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1), freq(n + 1), ptr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<int> seq = arr;
    sort(seq.begin(), seq.end());
    vector<vector<int>> st(n + 1);
    for (int i = 1; i <= n; i++)
        st[seq[i]].pb(i);
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        freq[seq[i]]++;
        p[i] = st[arr[i]][ptr[arr[i]]];
        ptr[arr[i]]++;
    }
    int even = 0;
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int cnt = dfs(p, vis, i);
            if (cnt % 2 == 0)
                even++;
        }
    }
    if (even % 2 == 0)
        return true;
    for (int i = 1; i <= n; i++)
        if (freq[i] > 1)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}