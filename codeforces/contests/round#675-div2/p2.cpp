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
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < m; j++)
                cin >> mat[i][j];
        ll op = 0;
        for (ll i = 0; i < n / 2; i++)
        {
            for (ll j = 0; j < m / 2; j++)
            {
                ll avg[4] = {mat[i][j], mat[i][m - 1 - j], mat[n - 1 - i][m - 1 - j], mat[n - 1 - i][j]};
                sort(avg, avg + 4);
                ll mid = min(avg[1], avg[2]);
                for (ll v : avg)
                    op = op + abs(v - mid);
            }
        }

        // Middle Row
        if (n % 2 == 1)
        {
            ll i = n / 2;
            for (ll j = 0; j < m / 2; j++)
                op = op + abs(mat[i][j] - mat[i][m - 1 - j]);
        }

        // Middle Column
        if (m % 2 == 1)
        {
            ll j = m / 2;
            for (ll i = 0; i < n / 2; i++)
                op = op + abs(mat[i][j] - mat[n - 1 - i][j]);
        }
        cout << op << "\n";
    }
    return 0;
}