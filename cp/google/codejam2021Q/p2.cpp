#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e7 + 5;
map<char, int> mp;
int mu(vector<vector<int>> &dp, string &str, vector<int> &cost, int cur, int last)
{
    if (cur == str.length())
        return 0;
    if (dp[cur][last] == inf)
    {
        if (str[cur] == '?')
        {
            for (int j = 0; j < 2; j++)
            {
                int add = (j != last) ? cost[j] : 0;
                dp[cur][last] = min(dp[cur][last], add + mu(dp, str, cost, cur + 1, j));
            }
        }
        else
        {
            int j = mp[str[cur]];
            int add = (j != last) ? cost[j] : 0;
            dp[cur][last] = min(dp[cur][last], add + mu(dp, str, cost, cur + 1, j));
        }
    }
    return dp[cur][last];
}

int solve()
{
    int x, y;
    string str;
    cin >> x >> y >> str;
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(2, inf));
    vector<int> cost = {y, x};
    if (str[0] == '?')
        return min(mu(dp, str, cost, 1, 0), mu(dp, str, cost, 1, 1));
    return mu(dp, str, cost, 1, mp[str[0]]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mp['C'] = 0;
    mp['J'] = 1;
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}