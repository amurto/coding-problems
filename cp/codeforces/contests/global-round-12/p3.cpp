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
        int n, cnt = 0, m = 0;
        cin >> n;
        vector<vector<char>> grid(n, vector<char>(n));
        vector<pair<int, int>> X = {{0, 0}, {0, 1}, {0, 2}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'X')
                {
                    cnt++;
                    X[(i + j) % 3].first++;
                }
            }
        }
        sort(X.begin(), X.end());
        int mn = X[0].second;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i + j) % 3 == mn && grid[i][j] == 'X')
                {
                    grid[i][j] = 'O';
                    m++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << grid[i][j];
            cout << "\n";
        }
    }
    return 0;
}