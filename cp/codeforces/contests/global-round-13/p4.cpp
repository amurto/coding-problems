#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int u, v;
    cin >> u >> v;
    if (u > v)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ((i & j) == j)
                cout << i << " -> " << i + j << "\n";
    // int t;
    // cin >> t;
    // while (t-- > 0)
    //     solve();
    return 0;
}