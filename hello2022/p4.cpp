#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const ll inf = 1e18;
ll solve()
{
    int n;
    cin >> n;
    int sz = 2 * n;
    ll res = inf, sum = 0;
    vector<vector<ll>> grid(sz + 1, vector<ll>(sz + 1)), dp(sz + 1, vector<ll>(sz + 1));
    for (int i = 1; i <= sz; i++)
        for (int j = 1; j <= sz; j++)
            cin >> grid[i][j];
    vector<pii> pts = {{1, n + 1}, {1, 2 * n}, {n, n + 1}, {n, 2 * n}, {n + 1, 1}, {n + 1, n}, {2 * n, 1}, {2 * n, n}};
    for (int i = n + 1; i <= 2 * n; i++)
        for (int j = n + 1; j <= 2 * n; j++)
            sum += grid[i][j];
    for (pii pt : pts)
        res = min(res, sum + grid[pt.first][pt.second]);
    return res;
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