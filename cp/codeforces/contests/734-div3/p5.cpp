#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    int v = (n * m) / 2 - h;
    string chs = "";
    for (char ch = 'a'; ch <= 'z'; ch++)
        chs.pb(ch);
    // try to place all horizontal on m
for (int is_rotate=0; is_rotate)
    if (!(n % 2 == 1 && h * 2 < m))
    {
        vector<vector<char>> grid(n, vector<char>(m, '.'));
        string yz = "yz";
        int rem = h, r = 0;
        if (n % 2 == 1)
        {
            for (int j = 1, c = 0; j < m; j += 2, c++)
                grid[0][j - 1] = grid[0][j] = yz[c % 2];
            r++;
        }

        rem -= (m / 2);
        if (rem % 2 == 0)
        {
            for (int j = 1; rem > 0 && j < m; j += 2)
            {
                // cols -> j-1, j
                for (int i = r, k = j; rem > 0 && i < n; i++, rem--, k++)
                    grid[i][j - 1] = grid[i][j] = chs[k % 22];
            }
            // done with horizontal dominoes
            string wx = "wx";
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++) 
            }
        }
    }
    // try to place all vertical on n
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