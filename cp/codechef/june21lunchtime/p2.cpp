#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

bool pos(vector<vector<int>> &dp, int n, int m, int k)
{
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cout << dp[i][j];
    //     cout << "\n";
    // }
    // cout << "\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    for (int i = k; i <= n; i++)
        for (int j = k; j <= m; j++)
            if (dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k] == k * k)
                return true;
    return false;
}

string solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int sz = n * m;
    vector<pii> arr(sz);
    for (int i = 0; i < sz; i++)
        cin >> arr[i].first >> arr[i].second;
    int low = 1, high = sz, res = sz + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        vector<vector<int>> g0(n + 1, vector<int>(m + 1)), g1(n + 1, vector<int>(m + 1));
        for (int i = 0; i < mid; i++)
        {
            if (i & 1)
                g1[arr[i].first][arr[i].second]++;
            else
                g0[arr[i].first][arr[i].second]++;
        }
        if (pos(g0, n, m, k) || pos(g1, n, m, k))
        {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    if (res == sz + 1)
        return "Draw";
    return (res & 1) ? "Alice" : "Bob";
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