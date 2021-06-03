#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string rgb = "RGB";
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> cnt(3), ids(3);
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < 3; i++)
        cin >> cnt[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return cnt[i1] < cnt[i2]; });
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (cnt[ids[(i + j) % 2]]-- > 0)
                grid[i][j] = ids[(i + j) % 2];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == -1)
                grid[i][j] = ids[2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << rgb[grid[i][j]];
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