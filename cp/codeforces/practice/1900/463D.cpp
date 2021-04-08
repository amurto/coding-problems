// https://codeforces.com/contest/463/problem/D
// Gargari and Permutations

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int gap(vector<int> &dp, vector<vector<int>> &pos, int cur, int n, int k)
{
    if (dp[cur] == -1)
    {
        int res = 1;
        for (int j = 1; j <= n; j++)
        {
            if (cur == j)
                continue;
            int cnt = 0;
            for (int i = 0; i < k; i++)
                if (pos[i][cur] < pos[i][j])
                    cnt++;
            if (cnt == k)
                res = max(res, 1 + gap(dp, pos, j, n, k));
        }
        dp[cur] = res;
    }
    return dp[cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, v;
    cin >> n >> k;
    vector<vector<int>> pos(k, vector<int>(n + 1));
    vector<int> dp(n + 1, -1);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v;
            pos[i][v] = j;
        }
    }
    for (int i = 1; i <= n; i++)
        gap(dp, pos, i, n, k);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[i]);
    cout << res << "\n";
    return 0;
}