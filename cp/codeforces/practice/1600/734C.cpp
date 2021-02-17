// https://codeforces.com/contest/734/problem/C
// Anton and Making Potions

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int op(int mp, vector<int> &c, vector<int> &d)
{
    int idx = upper_bound(d.begin(), d.end(), mp) - d.begin();
    idx--;
    return (idx >= 0 && idx < d.size()) ? c[idx] : 0;
}

ll solve()
{
    int n, m, k, x, s;
    cin >> n >> m >> k >> x >> s;
    vector<int> a(m), b(m), c(k), d(k);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < k; i++)
        cin >> c[i];
    for (int i = 0; i < k; i++)
        cin >> d[i];
    ll res = max(0, n - op(s, c, d)) * 1ll * x;
    for (int i = 0; i < m; i++)
        if (b[i] <= s)
            res = min(res, max(0, n - op(s - b[i], c, d)) * 1ll * a[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}