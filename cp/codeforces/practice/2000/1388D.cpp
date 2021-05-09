// https://codeforces.com/contest/1388/problem/D
// Captain Flint and Treasure

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2e5 + 5;
vector<int> g[N];
int a[N], b[N];

ll dfs(vector<int> &res, vector<int> &tmp, ll &sum, int cur)
{
    ll val = 1ll * a[cur];
    for (int e : g[cur])
        val += dfs(res, tmp, sum, e);
    sum += val;
    if (val >= 0)
        res.pb(cur);
    else
        tmp.pb(cur);
    return max(0ll, val);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        if (b[i] != -1)
            g[b[i]].pb(i);
    vector<int> res;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] == -1)
        {
            vector<int> tmp;
            dfs(res, tmp, sum, i);
            reverse(tmp.begin(), tmp.end());
            for (int t : tmp)
                res.pb(t);
        }
    }
    cout << sum << "\n";
    for (int r : res)
        cout << r << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}