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
ll solve()
{
    int h, w, h1, w1, h2, w2;
    cin >> h >> w >> h1 >> w1 >> h2 >> w2;
    vector<vector<ll>> grid(h + 1, vector<ll>(w + 1)), pre(h + 1, vector<ll>(w + 1));
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> grid[i][j];
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            pre[i][j] = grid[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    h2 = min(h1, h2);
    w2 = min(w1, w2);
    vector<vector<ll>> tk(h + 1, vector<ll>(w + 1)), ak(h + 1, vector<ll>(w + 1));
    for (int i = h1; i <= h; i++)
        for (int j = w1; j <= w; j++)
            tk[i][j] = pre[i][j] - pre[i - h1][j] - pre[i][j - w1] + pre[i - h1][j - w1];
    for (int i = h2; i <= h; i++)
        for (int j = w2; j <= w; j++)
            ak[i][j] = pre[i][j] - pre[i - h2][j] - pre[i][j - w2] + pre[i - h2][j - w2];
    vector<vector<ll>> mx(h + 1, vector<ll>(w + 1)), best(h + 1, vector<ll>(w + 1));
    int n = h1 - h2 + 1, m = w1 - w2 + 1;
    for (int j = 1; j <= w; j++)
    {
        multiset<ll> ms;
        for (int i = 1; i <= h; i++)
        {
            if (i - n > 0)
                ms.erase(ms.lower_bound(ak[i - n][j]));
            ms.insert(ak[i][j]);
            mx[i][j] = *ms.rbegin();
        };
    }
    ll res = 0;
    for (int i = 1; i <= h; i++)
    {
        multiset<ll> ms;
        for (int j = 1; j <= w; j++)
        {
            if (j - m > 0)
                ms.erase(ms.lower_bound(mx[i][j - m]));
            ms.insert(mx[i][j]);
            best[i][j] = *ms.rbegin();
        }
    }
    for (int i = h1; i <= h; i++)
        for (int j = w1; j <= w; j++)
            res = max(res, tk[i][j] - best[i][j]);
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