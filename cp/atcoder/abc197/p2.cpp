#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int h, w, x, y, res = 1;
    cin >> h >> w >> x >> y;
    string grid[h];
    for (int i = 0; i < h; i++)
        cin >> grid[i];
    x--;
    y--;
    for (int i = x - 1; i >= 0 && grid[i][y] != '#'; i--)
        res++;
    for (int i = x + 1; i < h && grid[i][y] != '#'; i++)
        res++;
    for (int j = y - 1; j >= 0 && grid[x][j] != '#'; j--)
        res++;
    for (int j = y + 1; j < w && grid[x][j] != '#'; j++)
        res++;
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