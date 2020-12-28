#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 101;
int dp[N][N];
bool rbs(string &str, int cur, int op)
{
    if (op < 0)
        return false;
    if (cur == str.length())
        return (op == 0);
    if (dp[cur][op] == -1)
    {
        int res = 0;
        if (str[cur] == '(')
            res = rbs(str, cur + 1, op + 1);
        else if (str[cur] == ')')
            res = rbs(str, cur + 1, op - 1);
        else
            res = rbs(str, cur + 1, op + 1) | rbs(str, cur + 1, op - 1);
        dp[cur][op] = res;
    }
    return dp[cur][op];
}

bool solve()
{
    string str;
    cin >> str;
    int n = str.length(), op = 0, cl = 0, q = 0;
    if (n % 2 == 1)
        return false;
    memset(dp, -1, sizeof(dp));
    return rbs(str, 0, 0);
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