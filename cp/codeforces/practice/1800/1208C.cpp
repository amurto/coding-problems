// https://codeforces.com/contest/1208/problem/C
// Magic Grid

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n)), sam = {{8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};
    int cur = 0;
    
    for (int r = 0; r < n; r += 4)
        for (int c = 0; c < n; c += 4, cur += 16)
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    grid[r + i][c + j] = cur + sam[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}