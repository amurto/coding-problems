#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m, res = 0;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++)
            cin >> grid[i];
        for (int i = 0; i < n - 1; i++)
            res += grid[i][m - 1] == 'R';
        for (int j = 0; j < m - 1; j++)
            res += grid[n - 1][j] == 'D';
        cout << res << "\n";
    }
    return 0;
}