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

vector<int> z_function(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<vector<int>> dp(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++)
    {
        string cur = str.substr(i, n - i);
        vector<int> z = z_function(cur);
        for (int j = i + 1; j < n; j++)
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
        for (int j = i + 1; j < n; j++)
            if (j + z[j - i] < n && str[i + z[j - i]] < str[j + z[j - i]])
                dp[j][j + z[j-i]] = max(dp[j][j + z[j-i]], dp[i][n - 1] + 1);
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            mx = max(mx, dp[i][j]);
    return mx;
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