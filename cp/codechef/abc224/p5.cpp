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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> r(n), c(n), a(n), ids(n), dp(n), rmx(h + 1), cmx(w + 1);
    for (int i = 0; i < n; i++)
        cin >> r[i] >> c[i] >> a[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return a[i1] > a[i2]; });
    for (int i = 0; i < n;)
    {
        int itr = i;
        while (itr < n && a[ids[i]] == a[ids[itr]])
            itr++;
        for (int j = i; j < itr; j++)
            dp[ids[j]] = 1 + max(rmx[r[ids[j]]], cmx[c[ids[j]]]);
        while (i < itr)
        {
            rmx[r[ids[i]]] = max(rmx[r[ids[i]]], dp[ids[i]]);
            cmx[c[ids[i]]] = max(cmx[c[ids[i]]], dp[ids[i]]);
            i++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << dp[i] - 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}