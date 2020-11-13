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
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> mat(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i + j) & 1)
                {
                    if (!(mat[i][j] & 1))
                        mat[i][j]++;
                }
                else
                {
                    if (mat[i][j] & 1)
                        mat[i][j]++;
                }
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}