#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, x;
    cin >> n >> m;
    vector<int> k(m), seq(m), res(m), c(n + 1);
    int req = (m + 1) / 2;
    vector<vector<int>> d(m);
    for (int i = 0; i < m; i++)
    {
        seq[i] = i;
        cin >> k[i];
        for (int j = 0; j < k[i]; j++)
        {
            cin >> x;
            d[i].pb(x);
        }
    }
    auto cmp = [&](int &i1, int &i2) {
        return k[i1] < k[i2];
    };
    sort(seq.begin(), seq.end(), cmp);
    for (int i = 0; i < m; i++)
    {
        int cur = seq[i];
        int j = 0;
        while (j < k[cur] && c[d[cur][j]] >= req)
            j++;
        if (j < k[cur])
        {
            res[cur] = d[cur][j];
            c[d[cur][j]]++;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++)
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