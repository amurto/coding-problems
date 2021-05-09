// https://codeforces.com/contest/1380/problem/D
// Berserk And Fireball

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, m, k;
    ll x, y, res = 0;
    cin >> n >> m >> x >> k >> y;
    vector<int> a(n + 1), b(m), seq;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
    {
        if (a[i] == b[j])
        {
            seq.pb(i);
            j++;
        }
    }
    if (j < m)
        return -1;
    seq.pb(n);
    int last = 0, id = -1;
    for (int i = 0; i < seq.size(); i++)
    {
        int len = seq[i] - id - 1;
        if (len <= 0)
        {
            last = a[seq[i]];
            id = seq[i];
            continue;
        }
        int mx = 0;
        for (int j = id + 1; j < seq[i]; j++)
            mx = max(mx, a[j]);
        if (len < k && mx > max(last, a[seq[i]]))
            return -1;
        ll c1 = 1e18, c2 = 1e18;
        if (mx < max(last, a[seq[i]]))
            c1 = y * len;
        c2 = y * (len % k);
        len /= k;
        ll c3 = x * len;
        if (len > 1)
            c3 = min(c3, y * k * (len - 1) + x);
        c2 += c3;
        res += min(c1, c2);
        last = a[seq[i]];
        id = seq[i];
    }
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