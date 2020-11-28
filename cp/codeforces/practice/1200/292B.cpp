#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for (int i=0; i<m; i++)
    {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int star = 0, one = 0, two = 0;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == n-1)
            star++;
        else if (g[i].size() == 1)
            one++;
        else if (g[i].size() == 2)
            two++;
    }
    if (star == 1 && one == n - 1)
        cout << "star topology";
    else if (two == n)
        cout << "ring topology";
    else if (one == 2 && two == n - 2)
        cout << "bus topology";
    else
        cout << "unknown topology";
    return 0;
}