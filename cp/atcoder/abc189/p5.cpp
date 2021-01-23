#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    vector<ll> tx(m + 1), ty(m + 1), r(m + 1);
    tx[0] = 1;
    ty[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        tx[i] = tx[i - 1];
        ty[i] = ty[i - 1];
        r[i] = r[i - 1];
        cin >> t;
        if (t <= 2)
        {
            swap(tx[i], ty[i]);
            if (t == 1)
            {
                ty[i] *= -1;
                r[i]++;
            }
            else
            {
                tx[i] *= -1;
                r[i]--;
            }
        }
        if (t > 2)
        {
            cin >> p;
            if (t == 3)
                tx[i] = p + p - tx[i];
            else
                ty[i] = p + p - ty[i];
        }
    }
    cin >> q;
    while (q-- > 0)
    {
        cin >> a >> b;
        b--;
        ll tr = r[a];
        if (tr < 0)
            tr *= -1;
        ll rx = x[b], ry = y[b];
        if (tr % 2)
            swap(rx, ry);
        ll xc = (1 + tx[a]) / 2, yc = (1 + ty[a]) / 2;
        if (tx[a] != 1)
            rx = xc + xc - rx;
        if (ty[a] != 1)
            ry = yc + yc - ry;
        cout << rx << " " << ry << "\n";
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