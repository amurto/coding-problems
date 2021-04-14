#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, m, t, res = 0;
    cin >> n >> m >> t;
    vector<int> p(n), a(m), k(m), ord(m);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> k[i];
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int &i1, int &i2) {
        if (k[i1] == k[i2])
            return a[i1] < a[i2];
        return k[i1] > k[i2];
    });
    for (int i = 0; i < m / 2; i++)
        t -= a[ord[i]];
    sort(p.begin(), p.end());
    for (int i = 0; t >= 0 && i < n; i++)
    {
        res += (p[i] <= t);
        t -= p[i];
    }
    return res;
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