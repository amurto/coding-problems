// https://codeforces.com/contest/75/problem/D
// Big Maximum Sum

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = -1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll dp[n][4];
    for (int i = 0; i < n; i++)
    {
        ll l, sum = 0, L = inf, R = inf, ks = 0, kd = inf;
        cin >> l;
        vector<ll> arr(l);
        for (int j = 0; j < l; j++)
        {
            cin >> arr[j];
            sum += arr[j];
            ks = max(ks + arr[j], arr[j]);
            kd = max(kd, ks);
            L = max(L, sum);
        }
        sum = 0;
        for (int j = l - 1; j >= 0; j--)
        {
            sum += arr[j];
            R = max(R, sum);
        }
        dp[i][0] = L;
        dp[i][1] = sum;
        dp[i][2] = R;
        dp[i][3] = kd;
    }
    ll res = inf, s = 0;
    for (int i = 0; i < m; i++)
    {
        int idx;
        cin >> idx;
        idx--;
        res = max({res, s + dp[idx][0], dp[idx][3]});
        s = max(s + dp[idx][1], dp[idx][2]);
        res = max(res, s);
    }
    cout << res << "\n";
    return 0;
}