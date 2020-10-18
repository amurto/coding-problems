// Get Maze Paths with Jumps

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void getMazePaths(string soFar, vector<string> &ans, int curi, int curj, int n, int m)
{
    if (curi < 0 || curi >= n || curj < 0 || curj >= m)
        return;
    if (curi == n - 1 && curj == m - 1)
    {
        ans.pb(soFar);
        return;
    }
    for (int j = 1; curj + j < m; j++)
        getMazePaths(soFar + 'h' + to_string(j), ans, curi, curj + j, n, m);

    for (int i = 1; curi + i < n; i++)
        getMazePaths(soFar + 'v' + to_string(i), ans, curi + i, curj, n, m);

    for (int d = 1; curi + d < n && curj + d < m; d++)
        getMazePaths(soFar + 'd' + to_string(d), ans, curi + d, curj + d, n, m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans;
    getMazePaths("", ans, 0, 0, n, m);
    for (string v : ans)
        cout << v << "\n";
    return 0;
}