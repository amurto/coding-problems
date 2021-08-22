#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll r, c, k, r1, c1, r2, c2, res = 1e18;
    cin >> r >> c >> k >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    if (r == 1 && c == 1)
        return 0;
    ll r_dis = min(c1 - 0, c - c2), c_dis = min(r1 - 0, r - r2);
    ll row_cuts = r2 - r1 + 1, col_cuts = c2 - c1 + 1;
    if (r1 == 0)
        row_cuts--;
    if (r2 == r)
        row_cuts--;
    if (c1 == 0)
        col_cuts--;
    if (c2 == c)
        col_cuts--;
    ll row_cut_dis = (c2 - c1 + k - 1) / k, col_cut_dis = (r2 - r1 + k - 1) / k;
    if (row_cuts + col_cuts == 0)
        return 0;
    // cut through row
    if (row_cuts > 0)
    {
        ll req = (r_dis + c2 - c1 + k - 1) / k;
        res = min(res, req + (row_cuts - 1) * row_cut_dis + (col_cuts)*col_cut_dis);
    }
    // cut through col
    if (col_cuts > 0)
    {
        ll req = (c_dis + r2 - r1 + k - 1) / k;
        res = min(res, req + (col_cuts - 1) * col_cut_dis + (row_cuts)*row_cut_dis);
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
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}