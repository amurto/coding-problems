#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    string str = "RW";
    vector<vector<char>> grid(n, vector<char>(m)), res(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    for (int c = 0; c < 2; c++)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res[i][j] = str[(i + j) % 2];
        bool pos = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] != '.' && grid[i][j] != res[i][j])
                    pos = false;
        if (pos)
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << res[i][j];
                cout << "\n";
            }
            return;
        }
        swap(str[0], str[1]);
    }
    cout << "NO\n";
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