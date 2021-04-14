// https://codeforces.com/contest/1360/problem/G
// A/B Matrix

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void inc(int &x, int m)
{
    x++;
    x %= m;
}
void solve()
{

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<int> row(n, a), col(m, b);
    if (n * a != m * b)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0, p = 0; i < n; i++, p += a)
    {
        p %= m;
        for (int j = p, cnt = 0; cnt < a; inc(j, m), cnt++)
            grid[i][j] = 1;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << "\n";
    }
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