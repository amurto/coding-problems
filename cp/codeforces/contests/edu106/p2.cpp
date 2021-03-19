#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 105;
int dp[N][N][2][2];

int br(string &str, int cur, int rem, int last, int adj, int n)
{
    if (cur == n)
        return rem > 0;
    if (dp[cur][rem][last][adj] == -1)
    {
        int e = str[cur] - '0', res = 0;
        if (e >= last)
            res = br(str, cur + 1, rem, e, 0, n);
        if (adj == 0)
            res = res || br(str, cur + 1, rem + 1, last, 1, n);
        dp[cur][rem][last][adj] = res;
    }
    return dp[cur][rem][last][adj];
}

bool solve()
{
    string str;
    cin >> str;
    int n = str.length();
    memset(dp, -1, sizeof(dp));
    return br(str, 0, 0, 0, 0, n);
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