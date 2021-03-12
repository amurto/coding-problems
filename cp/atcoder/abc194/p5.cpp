#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m, x;
    cin >> n >> m;
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pos[x].pb(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (pos[i].empty())
            return i;
        int last = -1;
        for (int j = 0; j < pos[i].size(); j++)
        {
            if (pos[i][j] - last - 1 >= m)
                return i;
            last = pos[i][j];
        }
        if (n - last - 1 >= m)
            return i;
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}