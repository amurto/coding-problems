#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

const ll d = 1e5;
void upd(ll &a, ll num, ll den)
{
    a = (a * num + den - 1) / den;
}

void solve()
{
    int n, m, t;
    cin >> n >> m;
    ll num, den, y;
    vector<int> vis(m + 1, -1);
    vis[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> num >> y;
        if (t == 1)
        {
            num = (num + d - 1) / d;
            for (ll j = 0; j <= m; j++)
                if (vis[j] >= 0 && vis[j] < i + 1)
                    for (ll a = j + num, cnt = 0; cnt < y && a <= m && vis[a] < 0; a += num, cnt++)
                        vis[a] = i + 1;
        }
        else
        {
            ll g = __gcd(num, d);
            num /= g;
            den = d / g;
            for (ll j = 1; j <= m; j++)
                if (vis[j] >= 0 && vis[j] < i + 1)
                    for (ll a = (j * num + den - 1) / den, cnt = 0; cnt < y && a <= m && vis[a] < 0; cnt++, upd(a, num, den))
                        vis[a] = i + 1;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << vis[i] << " ";
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