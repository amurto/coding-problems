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
        int n, m, x, y;
        cin >> n >> m;
        vector<int> row(n + 1), col(n + 1), parent(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            row[y] = x;
            col[x] = y;
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (row[i] == 0)
                continue;
            if (row[i] == i)
                parent[i] = i;
            if (col[i] == 0)
                parent[i] = -1;
            else 
                parent[i] = col[i];
        }
        for (int i=1; i<=n; i++) {
            
        }
        cout << res + 1 << "\n";
    }
    return 0;
}