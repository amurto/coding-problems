#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, q;
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> ids(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ids[arr[i]].pb(i);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r, x, res = 0;
        cin >> l >> r >> x;
        l--;
        r--;
        if (!ids[x].empty())
        {
            int id1 = lower_bound(ids[x].begin(), ids[x].end(), l) - ids[x].begin();
            int id2 = upper_bound(ids[x].begin(), ids[x].end(), r) - ids[x].begin();
            res = id2 - id1;
        }
        cout << res << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}