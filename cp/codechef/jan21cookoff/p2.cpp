#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 10;
char g[2][N][N];

void init()
{
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                g[k][i][j] = ((i + j) % 2 == k) ? '*' : '.';
}

int count(int n, int m, int p)
{
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[p][i][j] == '*')
                c++;
    return c;
}
int op(vector<vector<char>> &grid, int n, int m, int p)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res += (grid[i][j] != g[p][i][j]);
    return res;
}
int solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    int c0 = count(n, m, 0), c1 = count(n, m, 1);
    if (c0 == c1)
        return min(op(grid, n, m, 0), op(grid, n, m, 1));
    int r = 0;
    if (c0 < c1)
        r = 1;
    return op(grid, n, m, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}