// https://codeforces.com/contest/1185/problem/E
// Polycarp and Snakes

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1)), board(n + 1, vector<char>(m + 1, '.'));
    vector<vector<pii>> pos(2, vector<pii>(26));
    vector<pair<pii, pii>> res;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] != '.')
            {
                if (pos[0][grid[i][j] - 'a'].first == 0)
                    pos[0][grid[i][j] - 'a'] = {i, j};
                pos[1][grid[i][j] - 'a'] = {i, j};
            }
        }
    }
    for (int i = 24; i >= 0; i--)
    {
        if (pos[0][i].first == 0)
        {
            pos[0][i] = pos[0][i + 1];
            pos[1][i] = pos[1][i + 1];
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (pos[0][i].first > 0)
        {
            res.pb({pos[0][i], pos[1][i]});
            char ch = char('a' + i);
            if (pos[0][i].first == pos[1][i].first)
            {
                for (int j = pos[0][i].second; j <= pos[1][i].second; j++)
                    board[pos[0][i].first][j] = ch;
            }
            else
            {
                for (int j = pos[0][i].first; j <= pos[1][i].first; j++)
                    board[j][pos[0][i].second] = ch;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] != board[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    cout << res.size() << "\n";
    for (pair<pii, pii> p : res)
        cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << "\n";
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