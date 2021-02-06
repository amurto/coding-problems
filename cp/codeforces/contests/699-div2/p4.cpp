#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1005;
char g[N][N];

bool check(vector<int> &v, int m)
{
    int eq1 = m / 2 - 1, eq2 = m / 2 + (m & 1);
    eq1 %= 3;
    eq2 %= 3;
    return g[v[eq1]][v[(eq1 + 1) % 3]] == g[v[eq2]][v[(eq2 + 1) % 3]];
}
void solve()
{
    int n, m, a = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    vector<int> v;
    v.pb(0);
    v.pb(1);
    if (m == 1)
    {
        cout << "YES\n";
        cout << "1 2\n";
        return;
    }
    if (n == 2)
    {
        if (g[0][1] != g[1][0] && m % 2 == 0)
        {
            cout << "NO\n";
            return;
        }
    }
    else
    {
        v.pb(2);
        sort(v.begin(), v.end());
        do
        {
        } while (!check(v, m) && next_permutation(v.begin(), v.end()));
    }
    int sz = v.size(), cur = 0;
    cout << "YES\n";
    while (m-- >= 0)
    {
        cout << v[cur] + 1 << " ";
        cur = (cur + 1) % sz;
    }
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