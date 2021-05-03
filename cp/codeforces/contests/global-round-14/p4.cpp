#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> arr(n);
    vector<vector<int>> col(n + 1, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        col[arr[i]][i >= l]++;
    }
    int tl = 0, tr = 0;
    vector<vector<int>> st(2);
    for (int i = 1; i <= n; i++)
    {
        if (col[i][0] >= 1 && col[i][1] >= 1)
        {
            int m = min(col[i][0], col[i][1]);
            col[i][0] -= m;
            col[i][1] -= m;
        }
        tl += col[i][0];
        tr += col[i][1];
        if (col[i][0] > 0)
            st[0].pb(col[i][0]);
        if (col[i][1] > 0)
            st[1].pb(col[i][1]);
    }
    if (tl < tr)
    {
        swap(tl, tr);
        swap(st[0], st[1]);
    }
    int cost = 0;
    for (int i = 0; tl > tr && i < st[0].size(); i++)
    {
        while (st[0][i] > 1 && tl > tr)
        {
            tl -= 2;
            st[0][i] -= 2;
            cost++;
        }
    }
    return cost + tr + (tl - tr);
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