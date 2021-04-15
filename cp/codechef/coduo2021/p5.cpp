#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, k, d, x;
    cin >> n >> k;
    vector<vector<int>> g(n);
    vector<bool> vis(n);
    vector<int> cnt(k + 1), vote(k + 1);
    for (int i = 0; i < n; i++)
    {
        vector<bool> go(k + 1);
        cin >> d;
        for (int j = 0; j < d; j++)
        {
            cin >> x;
            go[x] = true;
        }
        for (int j = 1; j <= k; j++)
            if (!go[j])
                g[i].pb(j);
        if (!go[1])
            vis[i] = true;
        if (!vis[i])
            for (int e : g[i])
                cnt[e]++;
        else
            vote[1]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        sort(g[i].begin(), g[i].end(), [&](int &i1, int &i2) {
            if (vote[i1] == vote[i2])
                return cnt[i1] < cnt[i2];
            return vote[i1] < vote[i2];
        });
        int idx = g[i][0];
        vote[idx]++;
        for (int e : g[i])
            cnt[e]--;
    }
    int mx = 0;
    for (int i = 2; i <= k; i++)
        mx = max(mx, vote[i]);
    if (vote[1] > mx)
        return 0;
    return mx - vote[1] + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}