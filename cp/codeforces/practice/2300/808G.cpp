// https://codeforces.com/contest/808/problem/G
// Anthem of Berland

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
int T[N][26];

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
    if (T[k][ch - 'a'] == -1)
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
        T[k][ch - 'a'] = v;
    }
    return T[k][ch - 'a'];
}

int dfs(vector<vector<int>> &dp, vector<int> &pre, string &s, string &t, int cur, int k)
{
    if (cur == s.length())
        return k == t.length();
    if (dp[cur][k] == -1)
    {
        int eq = (k == t.length());
        int res = eq;
        char low = 'a', high = 'z';
        if (s[cur] != '?')
            low = high = s[cur];
        for (char c = low; c <= high; c++)
            res = max(res, eq + dfs(dp, pre, s, t, cur + 1, transition(pre, t, k, c)));
        dp[cur][k] = res;
    }
    return dp[cur][k];
}

int solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    memset(T, -1, sizeof(T));
    vector<int> pre = prefix_function(t);
    return dfs(dp, pre, s, t, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}