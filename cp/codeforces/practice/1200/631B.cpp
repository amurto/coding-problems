// https://codeforces.com/contest/631/problem/B
// Print Check

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, op, rc, col;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<int> tr(n), tc(m), ar(n), ac(m);
    for (int i = 1; i <= k; i++)
    {
        cin >> op >> rc >> col;
        rc--;
        if (op == 1)
        {
            ar[rc] = col;
            tr[rc] = i;
        }
        else
        {
            ac[rc] = col;
            tc[rc] = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tr[i] > tc[j])
                cout << ar[i] << " ";
            else
                cout << ac[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}