// https://codeforces.com/contest/1257/problem/E
// The Contest

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> sz(3);
    cin >> sz[0] >> sz[1] >> sz[2];
    int n = sz[0] + sz[1] + sz[2], v;
    vector<vector<int>> arr(3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < sz[i]; j++)
        {
            cin >> v;
            v--;
            arr[i].pb(v);
        }
        sort(arr[i].begin(), arr[i].end());
    }
    vector<int> pre(n), suf(n + 1);
    suf[n] = sz[2];
    for (int i = n - 1, j = sz[2] - 1; i >= 0; i--)
    {
        while (j >= 0 && arr[2][j] >= i)
            j--;
        suf[i] = j + 1;
        int lb = lower_bound(arr[1].begin(), arr[1].end(), i) - arr[1].begin();
        suf[i] += sz[1] - lb;
        suf[i] = min(suf[i], suf[i + 1]);
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j < sz[0] && arr[0][j] <= i)
            j++;
        pre[i] = sz[0] - j;
        int ub = upper_bound(arr[1].begin(), arr[1].end(), i) - arr[1].begin();
        pre[i] += ub;
    }
    int res = sz[0] + suf[0];
    for (int i = 0; i < n; i++)
        res = min(res, pre[i] + suf[i + 1]);
    cout << res << "\n";
    return 0;
}