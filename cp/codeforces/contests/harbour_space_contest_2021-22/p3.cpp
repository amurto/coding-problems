#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 11;
int dp[N][N][N];
int dfs(string &str, int cur, int a, int b)
{
    if (cur == 10)
        return 10;
    // check if game already over
    int rem = 10 - cur;
    int pA = a + rem / 2, pB = b + rem / 2;
    if (rem & 1)
        pB++;
    if (a > pB || b > pA)
        return cur;
    if (dp[cur][a][b] == -1)
    {
        int res = 10;
        int p = cur % 2;
        char ch = str[cur];
        vector<int> seq;

        if (ch == '?')
        {
            seq.pb(0);
            seq.pb(1);
        }
        else
            seq.pb(ch - '0');
        for (int v : seq)
        {
            if (p == 0)
                res = min(res, dfs(str, cur + 1, a + v, b));
            else
                res = min(res, dfs(str, cur + 1, a, b + v));
        }
        dp[cur][a][b] = res;
    }
    return dp[cur][a][b];
}
int solve()
{
    string str;
    cin >> str;
    memset(dp, -1, sizeof(dp));
    return dfs(str, 0, 0, 0);
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