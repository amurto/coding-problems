// https://codeforces.com/contest/1166/problem/E
// The LCMs Must be Large

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, m, c, v;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            cin >> v;
            arr[i][v - 1] = true;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            bool vis = false;
            for (int idx = 0; !vis && idx < n; idx++)
                vis = (arr[i][idx] && arr[j][idx]);
            if (!vis)
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "possible\n" : cout << "impossible\n";
    return 0;
}