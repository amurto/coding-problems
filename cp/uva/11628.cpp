// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2675
// 11628 - Another lottery

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while (cin >> n >> m && n && m)
    {
        vector<vector<ll>> mat(n, vector<ll>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        ll den = 0;
        for (int d = 0; d < n; d++)
            den += mat[d][m - 1];
        for (int i = 0; i < n; i++)
        {
            ll g = __gcd(mat[i][m - 1], den);
            cout << mat[i][m - 1] / g << " / " << den / g << "\n";
        }
    }
    return 0;
}
