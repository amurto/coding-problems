#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int C = 65;
int nxt[C][C][C];

int mask(int w, int e)
{
    if (e == w)
        return 0;
    else if (e == w / 2)
        return 1;
    else if (e == w / 10)
        return 2;
    return 3;
}

double dfs(vector<vector<vector<double>>> &dp, int r, int p, int s, int w, int e)
{
    if (r + p + s == 60)
        return 0;
    int dw = w / 10, de = mask(w, e);
    if (nxt[r][p][s] == -1)
    {
        double ex = 0;
        double rounds = 1.0 * (r + p + s);  
        double pr = (1.0 * s) / rounds, pp = (1.0 * r) / rounds, ps = (1.0 * p) / rounds;
        if (r + p + s == 0)
            pr = pp = ps = 1.0 / 3.0;
        vector<double> pbs = {pr, pp, ps};
        vector<int> defs = {2, 0, 1};
        for (int i = 0; i < 3; i++)
        {
            double ret = pbs[defs[i]] * w + pbs[i] * e + dfs(dp, r + (i == 0), p + (i == 1), s + (i == 2), w, e);
            if (ret >= ex)
            {
                nxt[r][p][s] = i;
                ex = ret;
            }
        }
        dp[r][p][s] = ex;
    }
    return dp[r][p][s];
}

string solve()
{
    int w, e;
    cin >> w >> e;
    int dw = w / 10, de = mask(w, e);
    vector<vector<vector<double>>> dp(C, vector<vector<double>>(C, vector<double>(C)));
    memset(nxt, -1, sizeof(nxt));
    double ex = dfs(dp, 0, 0, 0, w, e);
    string str, rps = "RPS";
    vector<int> c = {0, 0, 0};
    for (int i = 0; i < 60; i++)
    {
        str.pb(rps[nxt[c[0]][c[1]][c[2]]]);
        c[nxt[c[0]][c[1]][c[2]]]++;
    }
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, x;
    cin >> t >> x;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}