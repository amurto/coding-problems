#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, last = 0;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), idx(n + 1), c(m + 1), res(m + 1);
    vector<stack<int>> mp(max(n, m) + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (a[i] == b[i])
        {
            vis[i] = true;
            idx[b[i]] = i;
        }
        else
            mp[b[i]].push(i);
    }

    for (int i = 1; i <= m; i++)
        cin >> c[i];

    for (int i = m; i > 0; i--)
    {
        if (mp[c[i]].empty())
        {
            if (idx[c[i]] == 0 && last == 0)
            {
                cout << "NO\n";
                return;
            }
            if (last > 0)
                res[i] = last;
            else
                res[i] = idx[c[i]];
            last = res[i];
        }
        else
        {
            int tp = mp[c[i]].top();
            mp[c[i]].pop();
            res[i] = tp;
            vis[tp] = true;
            last = tp;
        }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
    for (int i = 1; i <= m; i++)
        cout << res[i] << " ";
    cout << "\n";
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