#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int inf = 1e9;
int solve()
{
    int n, cnt = 0, pre = 0;
    cin >> n;
    vector<int> arr(n), st(n + 1);
    vector<int> pdp(n + 1, inf);
    pdp[0] = 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
            st[++cnt] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            pre++;
            for (int j = 1; j <= min(cnt, pre); j++)
                dp[i][j] = pdp[j - 1] + abs(i - st[j]);
            for (int j = 1; j <= min(cnt, pre); j++)
                pdp[j] = min(pdp[j], dp[i][j]);
        }
    }
    return pdp[cnt];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}