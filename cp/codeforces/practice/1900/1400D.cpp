// https://codeforces.com/contest/1400/problem/D
// Zigzags

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    ll res = 0;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    vector<vector<ll>> pre(n + 1, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            pre[i][j] += pre[i - 1][j];
        pre[i][arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            res += pre[j - 1][arr[i]] * (pre[n][arr[j]] - pre[i][arr[j]]);
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