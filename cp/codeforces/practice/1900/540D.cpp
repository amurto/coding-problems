// https://codeforces.com/contest/540/problem/D
// Bad Luck Island

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

class game
{
public:
    double r = 0, s = 0, p = 0;
    game() {}
    game(double r, double s, double p) : r(r), s(s), p(p) {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    int r, s, p;
    cin >> r >> s >> p;
    game dp[r + 1][s + 1][p + 1];
    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            for (int k = 0; k <= p; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    if (i == 0)
                        dp[i][j][k] = game(0.0, 1.0, 0.0);
                    else if (j == 0)
                        dp[i][j][k] = game(0.0, 0.0, 1.0);
                    else if (k == 0)
                        dp[i][j][k] = game(1.0, 0.0, 0.0);
                    continue;
                }
                int sum = i * j + j * k + i * k;
                vector<int> ch = {i * j, j * k, i * k};
                vector<vector<int>> seq = {{i, j - 1, k},
                                           {i, j, k - 1},
                                           {i - 1, j, k}};
                for (int b = 0; b < 3; b++)
                {
                    double prob = (1.0 * ch[b]) / (1.0 * sum);
                    game g = dp[seq[b][0]][seq[b][1]][seq[b][2]];
                    g.r *= prob;
                    g.s *= prob;
                    g.p *= prob;
                    dp[i][j][k].r += g.r;
                    dp[i][j][k].s += g.s;
                    dp[i][j][k].p += g.p;
                }
            }
        }
    }
    cout << dp[r][s][p].r << " " << dp[r][s][p].s << " " << dp[r][s][p].p << "\n";
    return 0;
}