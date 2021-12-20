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

bool solve()
{
    int n;
    string str;
    cin >> n >> str;
    int cnt = 0, mx = n - 1;
    for (int i = 1; i < n; i++)
        if (str[i - 1] != str[i])
            cnt++;
    vector<int> dp(n);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= cnt; i--)
    {
        if (i + 1 < n && dp[i + 1] == 0)
            dp[i] = 1;
        if (i + 2 < n && dp[i + 2] == 0)
            dp[i] = 1;
    }
    return dp[cnt];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "JJ\n" : cout << "Uttu\n";
    return 0;
}