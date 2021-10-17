#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, a, b, c, root = 0;
    cin >> n >> m;
    vector<bool> vis(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        vis[b] = true;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            root = i;
    for (int i = 1; i <= n; i++)
        if (i != root)
            cout << root << " " << i << "\n";
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