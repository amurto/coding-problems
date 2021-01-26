// https://codeforces.com/contest/148/problem/C
// Terse princess

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (n == 1)
    {
        int ans = (a > 0 || b > 0) ? -1 : 1;
        cout << ans << "\n";
        return;
    }
    vector<int> res;
    if (b > 0)
    {
        res.pb(1);
        res.pb(3);
        b--;
    }
    else
    {
        res.pb(3);
        res.pb(1);
    }
    int pre = 4, mx = 3;
    while (b-- > 0)
    {
        res.pb(pre + 1);
        pre += res.back();
        mx = res.back();
    }
    while (a-- > 0)
    {
        res.pb(mx + 1);
        mx++;
    }
    if (res.size() > n)
    {
        cout << "-1\n";
        return;
    }
    while (res.size() < n)
        res.pb(res.back());
    for (int r : res)
        cout << r << " ";
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