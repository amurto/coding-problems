// https://codeforces.com/contest/758/problem/C
// Unfair Poll

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e18;
void solve()
{
    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    if (n == 1)
    {
        ll mn = k / m, mx = k / m + (k % m > 0);
        cout << mx << " " << mn << " ";
        if (y <= (k % m))
            cout << mx << "\n";
        else
            cout << mn << "\n";
        return;
    }
    ll itr = 2 * n * m - 2 * m;
    ll t = k / (itr);
    t *= 2;
    k %= (itr);
    ll mn = inf, mx = 0;
    vector<vector<ll>> grid(n, vector<ll>(m, t));
    for (int j = 0; j < m; j++)
        grid[0][j] /= 2;
    for (int j = 0; j < m; j++)
        grid[n - 1][j] /= 2;
    for (int i = 0; k > 0 && i < n - 1; i++)
        for (int j = 0; k > 0 && j < m; j++, k--)
            grid[i][j]++;
    for (int i = n - 1; k > 0 && i > 0; i--)
        for (int j = 0; k > 0 && j < m; j++, k--)
            grid[i][j]++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, grid[i][j]);
            mn = min(mn, grid[i][j]);
        }
    }
    cout << mx << " " << mn << " " << grid[x - 1][y - 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}