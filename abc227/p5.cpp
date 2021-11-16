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

ll solve()
{
    string str, key = "KEY";
    int ops;
    ll res = 0;
    cin >> str >> ops;
    int n = (int)str.length();
    ops = min(ops, n * n);
    map<char, int> pos;
    for (int i = 0; i < 3; i++)
        pos[key[i]] = i;
    array<int, 3> cnt{0, 0, 0};
    for (char ch : str)
        cnt[pos[ch]]++;
    vector<vector<vector<vector<ll>>>> dp(cnt[0] + 1, vector<vector<vector<ll>>>(cnt[1] + 1, vector<vector<ll>>(cnt[2] + 1, vector<ll>(ops + 1))));
    vector<vector<vector<vector<int>>>> st(cnt[0] + 1, vector<vector<vector<int>>>(cnt[1] + 1, vector<vector<int>>(cnt[2] + 1, vector<int>(3, n))));
    dp[0][0][0][0] = 1;
    for (int i = 0; i <= cnt[0]; i++)
    {
        for (int j = 0; j <= cnt[1]; j++)
        {
            for (int k = 0; k <= cnt[2]; k++)
            {
                int t = 0;
                array<int, 3> tmp{i, j, k};
                for (char ch : str)
                {
                    if (tmp[pos[ch]] == 0)
                    {
                        st[i][j][k][pos[ch]] = min(st[i][j][k][pos[ch]], t);
                        t++;
                    }
                    else
                        tmp[pos[ch]]--;
                }
            }
        }
    }
    for (int i = 0; i <= cnt[0]; i++)
    {
        for (int j = 0; j <= cnt[1]; j++)
        {
            for (int k = 0; k <= cnt[2]; k++)
            {
                if (i + j + k < n)
                {
                    for (int v = 0; v <= ops; v++)
                    {
                        if (dp[i][j][k][v] > 0)
                        {
                            for (int t = 0; t < 3; t++)
                            {
                                if (st[i][j][k][t] < n && v + st[i][j][k][t] <= ops)
                                {
                                    if (t == 0)
                                        dp[i + 1][j][k][v + st[i][j][k][t]] += dp[i][j][k][v];
                                    else if (t == 1)
                                        dp[i][j + 1][k][v + st[i][j][k][t]] += dp[i][j][k][v];
                                    else
                                        dp[i][j][k + 1][v + st[i][j][k][t]] += dp[i][j][k][v];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (ll x : dp[cnt[0]][cnt[1]][cnt[2]])
        res += x;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}