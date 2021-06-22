// https://codeforces.com/contest/432/problem/D
// Prefixes and Suffixes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Prefix Function from cp-algorithms
vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pre(n);
    for (int i = 1; i < n; i++)
    {
        int j = pre[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pre[j - 1];
        if (s[i] == s[j])
            j++;
        pre[i] = j;
    }
    return pre;
}

int dfs(vector<vector<int>> &g, vector<int> &sum, int cur, int last)
{
    sum[cur] = 1;
    for (int e : g[cur])
        if (e != last)
            sum[cur] += dfs(g, sum, e, cur);
    return sum[cur];
}

void solve()
{
    string str;
    cin >> str;
    int n = str.length();
    if (n == 1)
    {
        cout << "1\n";
        cout << "1 1\n";
        return;
    }
    vector<int> pre = prefix_function(str);
    vector<bool> vis(n);
    int cur = pre[n - 1] - 1;
    while (cur > 0)
    {
        vis[cur] = true;
        cur = pre[cur] - 1;
    }
    if (str[0] == str[n - 1])
        vis[0] = true;
    vis[n - 1] = true;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++)
        g[pre[i]].pb(i + 1);
    vector<int> sum(n + 1);
    dfs(g, sum, 0, 0);
    cout << count(vis.begin(), vis.end(), true) << "\n";
    for (int i = 0; i < n; i++)
        if (vis[i])
            cout << i + 1 << " " << sum[i + 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}