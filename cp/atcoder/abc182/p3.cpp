#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int t3(string &N, vector<vector<int>> &dp, int cur, int sum)
{
    if (cur == N.length())
        if (sum > 0 && sum % 3 == 0)
            return 0;
        else
            return INT_MIN;
    if (dp[cur][sum] == -1)
        dp[cur][sum] = max(1 + t3(N, dp, cur + 1, sum + N[cur] - 48), t3(N, dp, cur + 1, sum));
    return dp[cur][sum];
}

int solve()
{
    string N;
    cin >> N;
    int sum = 0;
    for (char ch : N)
        sum += ch - 48;
    if (sum % 3 == 0)
        return 0;
    vector<vector<int>> dp(N.length(), vector<int>(sum + 1, -1));
    int res = t3(N, dp, 0, 0);
    if (res <= 0)
        return -1;
    return N.length() - res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << solve() << "\n";
    return 0;
}