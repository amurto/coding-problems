// https://codeforces.com/contest/1059/problem/C
// Sequence Transformation

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve(vector<int> &res, int n, int mul)
{
    if (n == 0)
        return;
    if (n == 3)
    {
        res.pb(mul);
        res.pb(mul);
        res.pb(3 * mul);
        return;
    }
    int odd = (n + 1) / 2;
    while (odd-- > 0)
        res.pb(mul);
    solve(res, n / 2, mul * 2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> res;
    solve(res, n, 1);
    for (int r : res)
        cout << r << " ";
    return 0;
}