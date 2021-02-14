// https://codeforces.com/contest/610/problem/C
// Harmony Analysis

// Hadamard matrix
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int grid[1 << 9][1 << 9];

char mark(int x)
{
    return (x == 0) ? '*' : '+';
}

void harmony(int x, int k)
{
    if (x == k)
    {
        for (int i = 0; i < (1 << k); i++)
        {
            for (int j = 0; j < (1 << k); j++)
                cout << mark(grid[i][j]);
            cout << "\n";
        }
        return;
    }
    int cur = 1 << x;
    for (int i = cur; i < 2 * cur; i++)
        for (int j = 0; j < cur; j++)
            grid[i][j] = grid[i - cur][j];
    for (int i = 0; i < cur; i++)
        for (int j = cur; j < 2 * cur; j++)
            grid[i][j] = grid[i][j - cur];
    for (int i = cur; i < 2 * cur; i++)
        for (int j = cur; j < 2 * cur; j++)
            grid[i][j] = grid[i - cur][j - cur] ^ 1;
    harmony(x + 1, k);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    grid[0][0] = 1;
    int k;
    cin >> k;
    harmony(0, k);
    return 0;
}