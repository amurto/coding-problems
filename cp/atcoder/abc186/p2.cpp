#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int h, w, mn = 101, rem = 0;
    cin >> h >> w;
    int grid[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
            mn = min(mn, grid[i][j]);
        }
    }
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            rem += abs(grid[i][j] - mn);
    cout << rem << "\n";
    return 0;
}