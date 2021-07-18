#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void rotate(vector<vector<char>> &grid, int &n, int &m)
{
    vector<vector<char>> mat(m, vector<char>(n));
    for (int j = 0, a = 0; j < m; j++, a++)
        for (int i = n - 1, b = 0; i >= 0; i--, b++)
            mat[a][b] = grid[i][j];
    grid = mat;
    swap(n, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}