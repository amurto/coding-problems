#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

char XOR(char x)
{
    if (x == '0')
        return '1';
    return '0';
}

int solve(vector<vector<char>> &mat, vector<pair<int, int>> &moves, int i, int j)
{
    int op = 0;
    vector<queue<pair<int, int>>> store(2);
    store[mat[i][j] - '0'].push({i, j});
    store[mat[i][j + 1] - '0'].push({i, j + 1});
    store[mat[i + 1][j] - '0'].push({i + 1, j});
    store[mat[i + 1][j + 1] - '0'].push({i + 1, j + 1});
    if (store[0].size() == 4)
        return 0;
    while (!store[1].empty())
    {
        int one = store[1].size();
        if (one == 4)
        {
            for (int c = 0; c < 3; c++)
            {
                moves.pb(store[1].front());
                store[0].push(store[1].front());
                store[1].pop();
            }
        }
        else if (one == 3)
        {
            while (!store[1].empty())
            {
                moves.pb(store[1].front());
                store[0].push(store[1].front());
                store[1].pop();
            }
        }
        else if (one == 2)
        {
            while (!store[0].empty())
            {
                moves.pb(store[0].front());
                store[1].push(store[0].front());
                store[0].pop();
            }
            moves.pb(store[1].front());
            store[0].push(store[1].front());
            store[1].pop();
        }
        else if (one == 1)
        {
            while (!store[1].empty())
            {
                moves.pb(store[1].front());
                store[0].push(store[1].front());
                store[1].pop();
            }
            for (int c = 0; c < 2; c++)
            {
                moves.pb(store[0].front());
                store[1].push(store[0].front());
                store[0].pop();
            }
        }
        op++;
    }
    mat[i][j] = mat[i][j + 1] = mat[i + 1][j] = mat[i + 1][j + 1] = '0';
    return op;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m));
        vector<pair<int, int>> moves;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        int res = 0;

        if (n % 2 == 1 && m % 2 == 1)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (mat[i][m - 1] == '0')
                    continue;
                moves.pb({i, m - 1});
                mat[i][m - 1] = '0';
                moves.pb({i, m - 2});
                mat[i][m - 2] = XOR(mat[i][m - 2]);
                if (i == 0)
                {
                    moves.pb({i + 1, m - 2});
                    mat[i + 1][m - 2] = XOR(mat[i + 1][m - 2]);
                }
                else
                {
                    moves.pb({i - 1, m - 2});
                    mat[i - 1][m - 2] = XOR(mat[i - 1][m - 2]);
                }
                res++;
            }
            for (int j = m - 2; j >= 0; j--)
            {
                if (mat[n - 1][j] == '0')
                    continue;
                moves.pb({n - 1, j});
                mat[n - 1][j] = '0';
                moves.pb({n - 2, j});
                mat[n - 2][j] = XOR(mat[n - 2][j]);
                if (j == 0)
                {
                    moves.pb({n - 2, j + 1});
                    mat[n - 2][j + 1] = XOR(mat[n - 2][j + 1]);
                }
                else
                {
                    moves.pb({n - 2, j - 1});
                    mat[n - 2][j - 1] = XOR(mat[n - 2][j - 1]);
                }
                res++;
            }
        }
        else if (n % 2 == 1)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (mat[n - 1][j] == '0')
                    continue;
                moves.pb({n - 1, j});
                mat[n - 1][j] = '0';
                moves.pb({n - 2, j});
                mat[n - 2][j] = XOR(mat[n - 2][j]);
                if (j == 0)
                {
                    moves.pb({n - 2, j + 1});
                    mat[n - 2][j + 1] = XOR(mat[n - 2][j + 1]);
                }
                else
                {
                    moves.pb({n - 2, j - 1});
                    mat[n - 2][j - 1] = XOR(mat[n - 2][j - 1]);
                }
                res++;
            }
        }
        else if (m % 2 == 1)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (mat[i][m - 1] == '0')
                    continue;
                moves.pb({i, m - 1});
                mat[i][m - 1] = '0';
                moves.pb({i, m - 2});
                mat[i][m - 2] = XOR(mat[i][m - 2]);
                if (i == 0)
                {
                    moves.pb({i + 1, m - 2});
                    mat[i + 1][m - 2] = XOR(mat[i + 1][m - 2]);
                }
                else
                {
                    moves.pb({i - 1, m - 2});
                    mat[i - 1][m - 2] = XOR(mat[i - 1][m - 2]);
                }
                res++;
            }
        }
        for (int i = 0; i < n - 1; i += 2)
            for (int j = 0; j < m - 1; j += 2)
                res += solve(mat, moves, i, j);
        cout << res << "\n";
        for (int i = 0; i < moves.size(); i += 3)
        {
            cout << moves[i].first + 1 << " " << moves[i].second + 1 << " ";
            cout << moves[i + 1].first + 1 << " " << moves[i + 1].second + 1 << " ";
            cout << moves[i + 2].first + 1 << " " << moves[i + 2].second + 1 << " ";
            cout << "\n";
        }
    }
    return 0;
}