#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 5e5 + 1;
vector<ll> parent(N), color(N);

ll root(ll x)
{
    if (x == parent[x])
        return x;
    return root(parent[parent[x]]);
}

void dsunion(ll x, ll y)
{
    ll rx = root(x), ry = root(y);
    if (rx == ry)
        return;

    // by color
    if (color[rx] < color[ry])
        swap(rx, ry);
    color[ry] -= color[rx];
    parent[ry] = parent[rx];
}

void solve()
{
    ll type, a, b = 0;
    cin >> type >> a;
    if (type == 1)
    {
        cin >> b;
        dsunion(a, b);
    }
    else if (type == 2)
    {
        cin >> b;
        color[root(a)] += b;
    }
    else if (type == 3)
    {
        ll ans = color[a];
        while (a != parent[a])
        {
            a = parent[a];
            ans += color[a];
        }
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        ll n, q;
        cin >> n >> q;
        for (ll i = 1; i <= n; i++)
        {
            parent[i] = i;
            color[i] = 0;
        }
        while (q-- > 0)
            solve();
    }
    return 0;
}