// Get Maze Paths

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
    getMazePaths(soFar + 'h', ans, curi, curj + 1, n, m);
    getMazePaths(soFar + 'v', ans, curi + 1, curj, n, m);
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