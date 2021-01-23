#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pii;
#define pb push_back

void solve()
{
    int n, m, q, a, b, t;
    ll p;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    cin >> m;
    vector<vector<pair<ll, ll>>> c(m + 1, vector<pair<ll, ll>>(2));
    vector<int> r(m + 1);
    c[0][0].first = c[0][1].first = 1;
    for (int i = 1; i <= m; i++)
    {
        c[i][0] = c[i - 1][0];
        c[i][1] = c[i - 1][1];
        r[i] = r[i - 1];
        cin >> t;
        if (t <= 2)
        {
            r[i] ^= 1;
            swap(c[i][0], c[i][1]);
            c[i][t == 1].first *= -1;
            c[i][t == 1].second *= -1;
        }
        else
        {
            cin >> p;
            c[i][t - 3].first *= -1;
            c[i][t - 3].second = 2 * p - c[i][t - 3].second;
        }
    }
    cin >> q;
    while (q-- > 0)
    {
        cin >> a >> b;
        b--;
        ll cx = x[b], cy = y[b];
        if (r[a])
            swap(cx, cy);
        cx = cx * c[a][0].first + c[a][0].second;
        cy = cy * c[a][1].first + c[a][1].second;
        cout << cx << " " << cy << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}