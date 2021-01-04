// https://codeforces.com/contest/22/problem/C
// System Administrator

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll nn(int v)
{
    return v * 1ll * (v - 1) / 2;
}
void solve()
{
    int n, m, v;
    cin >> n >> m >> v;
    ll possible = nn(n) - (n - 2);
    if (m < n - 1 || m > possible)
    {
        cout << "-1\n";
        return;
    }
    vector<int> mark(n + 1);
    for (int i = 1; i <= n; i++)
        mark[i] = i;
    swap(mark[2], mark[v]);
    vector<pair<int, int>> e;
    for (int i = 1; i < n; i++)
        e.pb({mark[i], mark[i + 1]});
    m -= (n - 1);
    for (int i = n; m > 0 && i > 2; i--)
        for (int j = i - 2; m > 0 && j >= 2; j--, m--)
            e.pb({mark[j], mark[i]});
    for (pair<int, int> p : e)
        cout << p.first << " " << p.second << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}