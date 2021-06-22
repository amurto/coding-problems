// https://codeforces.com/contest/346/problem/B
// Lucky Common Subsequence

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 105, inf = 1e5;
int dp[N][N][N], nxt[N][N][N], vis[N][N][N], t[N][26];

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

int transition(vector<int> &pre, string &pat, int k, char ch)
{
    if (t[k][ch - 'A'] == -1)
    {
        int v = k;
        if (v == pat.length())
            v = pre[v - 1];
        if (ch == pat[v])
            v++;
        else
        {
            while (v > 0 && ch != pat[v])
                v = pre[v - 1];
            v += (ch == pat[v]);
        }
        t[k][ch - 'A'] = v;
    }
    return t[k][ch - 'A'];
}

int dfs(vector<string> &str, vector<int> &pre, int i, int j, int k)
{
    if (k == str[2].length())
        return -inf;
    if (i == str[0].length() || j == str[1].length())
        return 0;
    if (vis[i][j][k] == -1)
    {
        vis[i][j][k] = 0;
        int res = -inf;
        if (str[0][i] == str[1][j])
        {
            res = max(res, 1 + dfs(str, pre, i + 1, j + 1, transition(pre, str[2], k, str[0][i])));
            nxt[i][j][k] = 3;
        }
        int v1 = dfs(str, pre, i + 1, j, k);
        if (v1 > res)
        {
            res = v1;
            nxt[i][j][k] = 1;
        }
        int v2 = dfs(str, pre, i, j + 1, k);
        if (v2 > res)
        {
            res = v2;
            nxt[i][j][k] = 2;
        }
        dp[i][j][k] = res;
    }
    return dp[i][j][k];
}

string solve()
{
    vector<string> str(3);
    for (int i = 0; i < 3; i++)
        cin >> str[i];
    vector<int> pre = prefix_function(str[2]);
    memset(nxt, -1, sizeof(nxt));
    memset(vis, -1, sizeof(vis));
    memset(t, -1, sizeof(t));
    int mx = dfs(str, pre, 0, 0, 0);
    if (mx <= 0)
        return "0";
    string res = "";
    int i = 0, j = 0, k = 0;
    while (i < str[0].length() && j < str[1].length())
    {
        if (nxt[i][j][k] == 1)
            i++;
        else if (nxt[i][j][k] == 2)
            j++;
        else
        {
            res.pb(str[0][i]);
            k = transition(pre, str[2], k, str[0][i]);
            i++;
            j++;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}