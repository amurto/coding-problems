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

string solve()
{
    int n, cnt = 0;
    string str;
    cin >> n >> str;
    for (int i = 0; i < n;)
    {
        int r = i;
        while (r < n && str[i] == str[r])
            r++;
        cnt++;
        i = r;
    }
    vector<int> dp(cnt + 1);
    dp[1] = 1;
    for (int i = 3; i <= cnt; i++)
        if (dp[i - 2] + dp[i - 1] < 2)
            dp[i] = 1;
    return dp[cnt] ? "SAHID" : "RAMADHIR";
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