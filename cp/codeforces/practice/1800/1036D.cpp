// https://codeforces.com/contest/1187/problem/C
// Vasya And Array

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> res(n + 1), t(m), l(m), r(m);
    for (int i = 0; i < m; i++)
        cin >> t[i] >> l[i] >> r[i];
    vector<bool> vis(m);
    res[1] = n + 1;
    for (int i = 2; i <= n; i++)
    {
        res[i] = res[i - 1];
        int k = 1;
        for (int j = 0; j < m; j++)
            if (t[j] == 1 && l[j] <= i - 1 && r[j] >= i)
                k = 0;
        res[i] -= k;
        if (res[i] < res[i - 1])
        {
            for (int j = 0; j < m; j++)
                if (t[j] == 0 && l[j] <= i - 1 && r[j] >= i)
                    vis[j] = true;
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (t[j] == 0 && !vis[j])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}