#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n), tmp(n);
    vector<pii> ops1, ops2;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        tmp[i] = grid[i];
        for (int j = 0; j < m; j++)
            tmp[i][j] = '0';
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j > 0; j--)
        {
            if (grid[i][j] != tmp[i][j])
            {
                ops1.pb({i, j - 1});
                ops2.pb({i, j});
                tmp[i][j] = '1';
            }
        }
        if (grid[i][0] != tmp[i][0])
        {
            if (i > 0)
            {
                ops1.pb({i - 1, 0});
                ops2.pb({i, 0});
                tmp[i][0] = '1';
            }
        }
    }

    if (grid != tmp)
    {
        cout << "-1\n";
        return;
    }

    int q = (int)ops1.size();
    cout << q << "\n";
    for (int i = 0; i < q; i++)
        cout << ops1[i].first + 1 << " " << ops1[i].second + 1 << " " << ops2[i].first + 1 << " " << ops2[i].second + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}