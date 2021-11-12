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

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<int> t(n + 1);
    vector<bool> vis(n + 1);
    vector<vector<int>> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        int k, v;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            arr[i].pb(v);
        }
    }
    vis[n] = true;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int cur = q.front();
        res += t[cur];
        q.pop();
        for (int x : arr[cur])
        {
            if (!vis[x])
            {
                vis[x] = true;
                q.push(x);
            }
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}