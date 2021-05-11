#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m, x, y, cost = 0;
    cin >> n >> m >> x >> y;
    y = min(x * 2, y);
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<int> tiles;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
                cur++;
            else
            {
                tiles.pb(cur);
                cur = 0;
            }
        }
        if (cur > 0)
        {
            tiles.pb(cur);
            cur = 0;
        }
    }
    for (int t : tiles)
    {
        if (t & 1)
            cost += x;
        cost += y * (t / 2);
    }
    return cost;
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