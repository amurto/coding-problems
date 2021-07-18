#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int h, w, res = 4;
    cin >> h >> w;
    vector<vector<int>> grid(h, vector<int>(w));
    grid[0][0] = grid[0][w - 1] = grid[h - 1][0] = grid[h - 1][w - 1] = 1;
    for (int i = 0; i < h; i += h - 1)
        for (int j = 1; j < w - 1; j++)
            if (grid[i][j - 1] + grid[i][j + 1] == 0)
                grid[i][j] = 1;
    for (int j = 0; j < w; j += w - 1)
        for (int i = 1; i < h - 1; i++)
            if (grid[i - 1][j] + grid[i + 1][j] == 0)
                grid[i][j] = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cout << grid[i][j];
        cout << "\n";
    }
    cout << "\n";
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