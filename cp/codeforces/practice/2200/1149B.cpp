// https://codeforces.com/contest/1149/problem/B
// Three Religions

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

const int N = 255, K = 26;
int seq[3][N], dp[N][N][N];
void solve()
{
    int n, q;
    array<int, 3> lens{0, 0, 0};
    string str;
    cin >> n >> q >> str;
    int mx = n + 1;
    vector<vector<int>> nxt(mx + 1, vector<int>(K, mx));
    for (int i = n; i > 0; i--)
    {
        nxt[i] = nxt[i + 1];
        nxt[i][str[i - 1] - 'a'] = i;
    }
    nxt[0] = nxt[1];
    dp[0][0][0] = 0;
    for (int qq = 0; qq < q; qq++)
    {
        char t;
        cin >> t;
        if (t == '+')
        {
            int id;
            char ch;
            cin >> id >> ch;
            lens[id - 1]++;
            seq[id - 1][lens[id - 1]] = ch - 'a';
            array<int, 3> tmp{0, 0, 0};
            tmp[id - 1] = lens[id - 1];
            for (int i = tmp[0]; i <= lens[0]; i++)
            {
                for (int j = tmp[1]; j <= lens[1]; j++)
                {
                    for (int k = tmp[2]; k <= lens[2]; k++)
                    {
                        dp[i][j][k] = mx;
                        if (i - 1 >= 0 && dp[i - 1][j][k] < n)
                            dp[i][j][k] = min(dp[i][j][k], nxt[dp[i - 1][j][k] + 1][seq[0][i]]);
                        if (j - 1 >= 0 && dp[i][j - 1][k] < n)
                            dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j - 1][k] + 1][seq[1][j]]);
                        if (k - 1 >= 0 && dp[i][j][k - 1] < n)
                            dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k - 1] + 1][seq[2][k]]);
                    }
                }
            }
        }
        else
        {
            int id;
            cin >> id;
            array<int, 3> tmp{0, 0, 0};
            tmp[id - 1] = lens[id - 1];
            for (int i = tmp[0]; i <= lens[0]; i++)
                for (int j = tmp[1]; j <= lens[1]; j++)
                    for (int k = tmp[2]; k <= lens[2]; k++)
                        dp[i][j][k] = mx;
            lens[id - 1]--;
        }
        dp[lens[0]][lens[1]][lens[2]] < mx ? cout << "YES\n" : cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}