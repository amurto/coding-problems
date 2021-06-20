// https://codeforces.com/contest/494/problem/B
// Obsessive String

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

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

int solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<int> pre = prefix_function(t);
    vector<int> dp(n + 1), pdp(n + 1), tdp(n + 1);
    dp[0] = pdp[0] = tdp[0] = 1;
    int j = 0, last = -1;
    for (int i = 1; i <= n; i++)
    {
        char ch = s[i - 1];
        if (j == m)
            j = pre[j - 1];
        if (ch == t[j])
            j++;
        else
        {
            // Iterate over previous prefix matches
            while (j > 0 && ch != t[j])
                j = pre[j - 1];
            // Update j if a valid match is found, else no prefix exists at current char
            j += (ch == t[j]);
        }
        if (j == m)
            last = i - m;
        if (last >= 0)
            dp[i] = tdp[last];
        pdp[i] = add(pdp[i - 1], dp[i]);
        tdp[i] = add(tdp[i - 1], pdp[i]);
    }
    return add(pdp[n], -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}