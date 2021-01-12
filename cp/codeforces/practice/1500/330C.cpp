// https://codeforces.com/contest/330/problem/C
// Purification

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    vector<pair<int, int>> rm, cm;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                rm.pb({i + 1, j + 1});
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[j][i] == '.')
            {
                cm.pb({j + 1, i + 1});
                break;
            }
        }
    }
    if (rm.size() == n)
    {
        for (pair<int, int> m : rm)
            cout << m.first << " " << m.second << "\n";
        return;
    }
    if (cm.size() == n)
    {
        for (pair<int, int> m : cm)
            cout << m.first << " " << m.second << "\n";
        return;
    }
    cout << "-1\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}