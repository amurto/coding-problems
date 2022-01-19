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

const ll inf = 1e18;
class ladder
{
public:
    int r1, c1, r2, c2, h;
    ladder() {}
    ladder(int r1, int c1, int r2, int c2, int h) : r1(r1), c1(c1), r2(r2), c2(c2), h(h) {}
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> rooms(n);
    vector<vector<ll>> dp(n);
    vector<vector<ladder>> lads(n);
    vector<int> x(n), sz(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    rooms[0].pb(0);
    rooms[n - 1].pb(m - 1);
    for (int i = 0; i < k; i++)
    {
        int r1, c1, r2, c2, h;
        cin >> r1 >> c1 >> r2 >> c2 >> h;
        r1--;
        c1--;
        r2--;
        c2--;
        lads[r1].pb(ladder(r1, c1, r2, c2, h));
        rooms[r1].pb(c1);
        rooms[r2].pb(c2);
    }
    for (int i = 0; i < n; i++)
    {
        if (!rooms[i].empty())
        {
            sort(rooms[i].begin(), rooms[i].end());
            rooms[i].resize(unique(rooms[i].begin(), rooms[i].end()) - rooms[i].begin());
            sz[i] = (int)rooms[i].size();
            dp[i].resize(sz[i]);
            for (int j = 0; j < sz[i]; j++)
                dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (sz[i] > 0)
        {
            vector<ll> predp = dp[i];
            vector<ll> sufdp = dp[i];
            for (int j = 1; j < sz[i]; j++)
                predp[j] = min(predp[j], predp[j - 1] + (1ll * x[i] * abs(rooms[i][j] - rooms[i][j - 1])));
            for (int j = sz[i] - 2; j >= 0; j--)
                sufdp[j] = min(sufdp[j], sufdp[j + 1] + (1ll * x[i] * abs(rooms[i][j + 1] - rooms[i][j])));
            for (int j = 0; j < sz[i]; j++)
                dp[i][j] = min(dp[i][j], min(predp[j], sufdp[j]));
            for (ladder l : lads[i])
            {
                int id1 = lower_bound(rooms[i].begin(), rooms[i].end(), l.c1) - rooms[i].begin();
                int id2 = lower_bound(rooms[l.r2].begin(), rooms[l.r2].end(), l.c2) - rooms[l.r2].begin();
                if (dp[l.r1][id1] < inf)
                    dp[l.r2][id2] = min(dp[l.r2][id2], dp[l.r1][id1] - 1ll * l.h);
            }
        }
    }
    if (dp[n - 1].back() >= inf)
        cout << "NO ESCAPE\n";
    else
        cout << dp[n - 1].back() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}