// https://codeforces.com/contest/1075/problem/C
// The Tower is Going Home

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, x1, x2, y, res = INT_MAX;
    cin >> n >> m;
    vector<int> c(n), r;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> x2 >> y;
        if (x1 == 1)
            r.pb(x2);
    }
    sort(c.begin(), c.end());
    sort(r.begin(), r.end());
    for (int i = 0; i < n; i++)
    {
        int cnt = r.size() - (lower_bound(r.begin(), r.end(), c[i]) - r.begin());
        res = min(res, i + cnt);
    }
    int l = n + r.size() - (lower_bound(r.begin(), r.end(), N) - r.begin());
    res = min(res, l);
    cout << res << "\n";
    return 0;
}