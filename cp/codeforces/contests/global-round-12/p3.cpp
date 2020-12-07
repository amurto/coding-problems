#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};
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
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'X')
                    cnt++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool d = true;
                if (i - 1 >= 0 && i - 1 < n && j - 1 >= 0 && j - 1 < n && grid[i - 1][j - 1] != '.')
                    d = false;
                if (i + 1 >= 0 && i + 1 < n && j + 1 >= 0 && j + 1 < n && grid[i + 1][j + 1] == '.')
                    d = false;
                if (grid[i][j] == '.')
                    d = false;
                if (d) {
                    m++;
                    grid[i][j] = 'O';
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j];
            }
            cout << "\n";
        }
        cout << cnt << " " << m << "\n";
    }
    return 0;
}