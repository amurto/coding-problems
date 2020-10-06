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
        ll n, m;
        cin >> n >> m;
        ll mat[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        ll op = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < m / 2; j++)
            {
                ll avg[4] = {mat[i][j], mat[i][m - 1 - j], mat[n - 1 - i][m - 1 - j], mat[n - 1 - i][j]};
                sort(avg, avg + 4);
                for (ll v : avg)
                    op = op + abs(v - avg[1]);
            }
        }

        // Middle Row
        if (n % 2 == 1)
        {
            int i = n / 2;
            for (int j = 0; j < m / 2; j++)
                op = op + abs(mat[i][j] - mat[i][m - 1 - j]);
        }

        // Middle Column
        if (m % 2 == 1)
        {
            int j = m / 2;
            for (int i = 0; i < n / 2; i++)
                op = op + abs(mat[i][j] - mat[n - 1 - i][j]);
        }
        cout << op << "\n";
    }
    return 0;
}