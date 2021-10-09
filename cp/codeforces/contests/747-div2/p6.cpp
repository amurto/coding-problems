#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back

const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

map<string, int> col_id;
vector<int> opp = {1, 0, 3, 2, 5, 4};
void init()
{
    string s[6] = {"white", "yellow", "green", "blue", "red", "orange"};
    for (int i = 0; i < 6; i++)
        col_id[s[i]] = i;
}

int solve()
{
    int k, n = 0, res = 0;
    ll u;
    cin >> k >> n;
    string str;
    vector<pii> st, nodes;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> str;
        st.pb({u, col_id[str]});
        vector<ll> tmp;
        while (u > 0)
        {
            tmp.pb(u);
            u /= 2;
        }
        reverse(tmp.begin(), tmp.end());
        for (int j = 0; j < (int)tmp.size(); j++)
            nodes.pb({tmp[j], j});
    }
    sort(nodes.begin(), nodes.end());
    nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
    int sz = (int)nodes.size();
    vector<int> col(sz, -1);
    for (pii p : st)
    {
        pii c = {p.first, 0};
        int id = lower_bound(nodes.begin(), nodes.end(), c) - nodes.begin();
        if (id < sz && nodes[id].first == p.first)
            col[id] = p.second;
    }
    vector<vector<int>> pdp(k, vector<int>(6)), dp(sz, vector<int>(6));
    for (int j = 0; j < 6; j++)
        pdp[k - 1][j] = 1;
    for (int i = k - 2; i >= 0; i--)
    {
        pdp[i][0] = mul(16, mul(pdp[i + 1][0], pdp[i + 1][0]));
        for (int j = 1; j < 6; j++)
            pdp[i][j] = pdp[i][0];
    }
    for (int i = sz - 1; i >= 0; i--)
    {
        pii cur = nodes[i];
        vector<int> cols;
        if (col[i] == -1)
            for (int j = 0; j < 6; j++)
                cols.pb(j);
        else
            cols.pb(col[i]);
        for (int x : cols)
        {
            if (cur.second == k - 1)
                dp[i][x] = 1;
            else
            {
                array<ll, 2> children{2ll * cur.first, 2ll * cur.first + 1};
                array<int, 2> sum{0, 0};
                for (int c = 0; c < 2; c++)
                {
                    pii v = {children[c], cur.second + 1};
                    int id = lower_bound(nodes.begin(), nodes.end(), v) - nodes.begin();
                    if (id < sz && nodes[id].first == children[c])
                    {
                        for (int j = 0; j < 6; j++)
                            if (j != x && j != opp[x])
                                sum[c] = add(sum[c], dp[id][j]);
                    }
                    else
                    {
                        for (int j = 0; j < 6; j++)
                            if (j != x && j != opp[x])
                                sum[c] = add(sum[c], pdp[cur.second + 1][j]);
                    }
                }
                dp[i][x] = mul(sum[0], sum[1]);
            }
        }
    }
    for (int j = 0; j < 6; j++)
        res = add(res, dp[0][j]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}