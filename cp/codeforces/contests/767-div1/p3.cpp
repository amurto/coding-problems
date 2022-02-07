#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, res = 0;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n)), arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // (i-1,j)
            arr[i][j] = grid[i - 1][j];
            if (i - 2 >= 0)
                arr[i][j] ^= arr[i - 2][j];
            if (j - 1 >= 0)
                arr[i][j] ^= arr[i - 1][j - 1];
            if (j + 1 < n)
                arr[i][j] ^= arr[i - 1][j + 1];
            res ^= arr[i][j];
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}