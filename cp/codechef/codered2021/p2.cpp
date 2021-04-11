#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll mx = 1e16;
ll lcm(ll a, ll b)
{
    ll g = __gcd(a, b);
    if (a / g > mx / b)
        return mx;
    return (a / g) * b;
}

bool visited(vector<bool> &vis, int x, int n)
{
    for (int i = 0; i < n; i++)
        if (((x >> i) & 1) && vis[i])
            return true;
    return false;
}

int solve()
{
    int n, k;
    ll x;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sz = 1 << n;
    vector<pair<ll, int>> seq;
    for (int i = 1; i < sz; i++)
    {
        ll l = 1;
        for (int j = 0; l <= x && j < n; j++)
            if ((i >> j) & 1)
                l = lcm(l, arr[j]);
        if (l <= x)
            seq.pb({l, i});
    }
    auto cmp = [](pair<ll, int> &p1, pair<ll, int> &p2) {
        if (p1.first == p2.first)
            return __builtin_popcount(p1.second) > __builtin_popcount(p2.second);
        return p1.first < p2.first;
    };
    sort(seq.begin(), seq.end(), cmp);
    vector<bool> vis(n);
    for (pair<ll, int> p : seq)
    {
        if (visited(vis, p.second, n))
            continue;
        int cnt = __builtin_popcount(p.second);
        if (cnt > k)
        {
            for (int j = 0; j < n; j++)
                if ((p.second >> j) & 1)
                    vis[j] = true;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
        res += vis[i];
    return n - res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}