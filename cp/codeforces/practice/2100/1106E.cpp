// https://codeforces.com/contest/1106/problem/E
// Lunar New Year and Red Envelopes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5;
ll dp[N][205];

class node
{
public:
    int s, d, w;
    node() {}
    node(int s, int d, int w) : s(s), d(d), w(w) {}
    bool operator<(const node &other) const
    {
        if (w == other.w)
            return d < other.d;
        return w < other.w;
    }
};

ll dfs(vector<int> &dep, vector<int> &wmx, int cur, int rem, int n)
{
    if (cur == n + 1)
        return 0;
    if (dp[cur][rem] == -1)
    {
        ll res = 1ll * wmx[cur] + dfs(dep, wmx, dep[cur] + 1, rem, n);
        if (rem > 0)
            res = min(res, dfs(dep, wmx, cur + 1, rem - 1, n));
        dp[cur][rem] = res;
    }
    return dp[cur][rem];
}

ll solve()
{
    int n, m, k, s, t, d, w;
    cin >> n >> m >> k;
    vector<vector<node>> g(n + 1);
    vector<int> dep(n + 1), wmx(n + 1);
    for (int i = 0; i < k; i++)
    {
        cin >> s >> t >> d >> w;
        g[t].pb(node(s, d, w));
    }
    priority_queue<node> pq;
    for (int i = n; i > 0; i--)
    {
        while (!pq.empty() && pq.top().s > i)
            pq.pop();
        for (node p : g[i])
            pq.push(p);
        if (pq.empty())
            dep[i] = i;
        else
        {
            dep[i] = pq.top().d;
            wmx[i] = pq.top().w;
        }
    }
    memset(dp, -1, sizeof(dp));
    return dfs(dep, wmx, 1, m, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}