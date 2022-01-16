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

int calc_dis(int r1, int c1, int r2, int c2)
{
    return abs(r1 - r2) + abs(c1 - c2);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dis(n, vector<int>(m));
    vector<int> pts;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dis[i][j] = max({calc_dis(i, j, 0, 0), calc_dis(i, j, 0, m - 1), calc_dis(i, j, n - 1, 0), calc_dis(i, j, n - 1, m - 1)});
            pts.pb(dis[i][j]);
        }
    }
    sort(pts.begin(), pts.end());
    for (int i = n * m - 2; i >= 0; i--)
        pts[i] = min(pts[i], pts[i + 1]);
    for (int i = 0; i < n * m; i++)
        cout << pts[i] << " ";
    cout << "\n";
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