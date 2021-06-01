#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool median(vector<vector<int>> &grid, int n, int k, int mid, int req)
{
    int mx = 0;
    vector<vector<int>> subgrid(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            subgrid[i][j] = (grid[i][j] <= mid);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            subgrid[i][j] += subgrid[i - 1][j] + subgrid[i][j - 1] - subgrid[i - 1][j - 1];
    for (int i = k; i <= n; i++)
        for (int j = k; j <= n; j++)
            mx = max(mx, subgrid[i][j] - subgrid[i - k][j] - subgrid[i][j - k] + subgrid[i - k][j - k]);
    return mx >= req;
}

int solve()
{
    int n, k, res = 1e9 + 5;
    cin >> n >> k;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];
    int req = (k * k) / 2;
    if (k & 1)
        req++;
    int low = 0, high = 1e9 + 5;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (median(grid, n, k, mid, req))
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}