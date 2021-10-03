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

const int N = 2e5 + 5;
vector<int> g[N];
int arr[N];

int dfs(int cur, int last, int req, int &cnt)
{
    int x = arr[cur];
    for (int e : g[cur])
        if (e != last)
            x ^= dfs(e, cur, req, cnt);
    if (x == req)
    {
        cnt++;
        x = 0;
    }
    return x;
}

bool solve()
{
    int n, k, u, v, x = 0;
    cin >> n >> k;
    int mn = k;
    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        x ^= arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int cnt = 0;
    v = dfs(1, 1, x, cnt);
    if (x == 0)
        return true;
    while (cnt > mn)
        cnt -= 2;
    return cnt >= 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}