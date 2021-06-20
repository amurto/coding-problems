// https://codeforces.com/contest/291/problem/E
// Tree-String Problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, string> edge;
#define pb push_back

const int N = 1e5 + 5, M = 3e5 + 5;
vector<edge> g[N];
int dp[M][26];

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

int transition(string &t, vector<int> &pre, int &j, char ch)
{
    if (dp[j][ch - 'a'] == -1)
    {
        int v = j;
        if (v == t.length())
            v = pre[v - 1];
        if (ch == t[v])
            v++;
        else
        {
            while (v > 0 && ch != t[v])
                v = pre[v - 1];
            v += (ch == t[v]);
        }
        dp[j][ch - 'a'] = v;
    }
    j = dp[j][ch - 'a'];
    return j == t.length();
}

int dfs(string &t, vector<int> &pre, int cur, int k)
{
    int res = 0;
    for (edge e : g[cur])
    {
        int j = k;
        for (char ch : e.second)
            res += transition(t, pre, j, ch);
        res += dfs(t, pre, e.first, j);
    }
    return res;
}

int solve()
{
    int n, p;
    string str, t;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> p >> str;
        g[p].pb({i, str});
    }
    cin >> t;
    vector<int> pre = prefix_function(t);
    memset(dp, -1, sizeof(dp));
    return dfs(t, pre, 1, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}