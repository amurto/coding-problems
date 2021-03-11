#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve(vector<vector<char>> grid, vector<char> sym, int n, int req)
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.' || sym[(i + j) % 3] == '.')
                continue;
            if (grid[i][j] != sym[(i + j) % 3])
            {
                if (grid[i][j] == 'X')
                    grid[i][j] = 'O';
                else
                    grid[i][j] = 'X';
                m++;
            }
        }
    }
    if (m > req)
        return false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j];
        cout << "\n";
    }
    return true;
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
        int n, cnt = 0;
        cin >> n;
        vector<vector<char>> grid(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] != '.')
                    cnt++;
            }
        }
        int req = cnt / 3;
        vector<char> sym = {'.', 'O', 'X'};
        bool f = false;
        do
        {
            f = solve(grid, sym, n, req);
        } while (!f && next_permutation(sym.begin(), sym.end()));
    }
    return 0;
}