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

const int N = 1005, inf = 1e6 + 5;
int dp[N];

void init()
{
    queue<int> q;
    q.push(1);
    dp[1] = 0;
    vector<bool> vis(N);
    vis[1] = true;
    while (!q.empty())
    {
        int sz = (int)q.size();
        while (sz > 0)
        {
            int cur = q.front();
            q.pop();
            for (int dv = 1; dv <= cur; dv++)
            {
                int inc = cur / dv;
                if (cur + inc < N && !vis[cur + inc])
                {
                    q.push(cur + inc);
                    dp[cur + inc] = dp[cur] + 1;
                    vis[cur + inc] = true;
                }
            }
            sz--;
        }
    }
}

ll solve()
{
    int n, k, sum = 0;
    ll res = 0;
    cin >> n >> k;
    vector<int> b(n), c(n), dis(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
    {
        dis[i] = dp[b[i]];
        sum += dis[i];
    }
    if (sum <= k)
    {
        for (int x : c)
            res += (1ll * x);
        return res;
    }
    vector<ll> st(k + 1, -1);
    st[0] = 0;
    for (int i = 0; i < n; i++)
    {
        vector<ll> tst = st;
        for (int j = dis[i]; j <= k; j++)
            if (st[j - dis[i]] >= 0)
                tst[j] = max(tst[j], st[j - dis[i]] + 1ll * c[i]);
        swap(st, tst);
    }
    for (int i = 0; i <= k; i++)
        res = max(res, st[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}