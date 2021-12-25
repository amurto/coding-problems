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

const int N = 55;
int dp[N][N][N][N];
int solve()
{
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];
    vector<vector<int>> pre(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pre[i][j] = (grid[i][j] == '#');
            if (i - 1 >= 0)
                pre[i][j] += pre[i - 1][j];
            if (j - 1 >= 0)
                pre[i][j] += pre[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)
                pre[i][j] -= pre[i - 1][j - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            for (int r = i; r < n; r++)
            {
                for (int c = j; c < n; c++)
                {
                    // subgrid i,j,r,c
                    for (int k = 1; k <= n; k++)
                    {
                        int sum=pre[i][]
                        int res = );
                    }
                }
            }
        }
    }
    return dp[0][n - 1][];
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