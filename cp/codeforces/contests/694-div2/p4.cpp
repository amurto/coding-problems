#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MAX = 1e6 + 1;
int dp[MAX];
vector<int> ps;
void init()
{
    for (int i = 1; i * i <= MAX; i++)
        ps.pb(i * i);
}
void solve()
{
    int n, q, res = 0;
    cin >> n;
    vector<ll> arr(n);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        int lb = lower_bound(ps.begin(), ps.end(), arr[i]) - ps.begin();
        if (lb >= ps.size())
            continue;
        for (int j = lb; j >= 0; j--)
        {
            if (arr[i] % ps[j] == 0)
            {
                int root = arr[i] / ps[j];
                dp[root]++;
                res = max(res, dp[root]);
                break;
            }
        }
    }
    cin >> q;
    while (q-- > 0)
    {
        ll w;
        cin >> w;
        cout << res << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}