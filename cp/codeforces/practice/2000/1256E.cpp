// https://codeforces.com/contest/1256/problem/E
// Yet Another Division Into Teams

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), ids(n), dp(n), dir(n), team(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return arr[i1] < arr[i2]; });
    for (int i = 2; i < n; i++)
    {
        dp[i] = arr[ids[i]] - arr[ids[0]];
        dir[i] = -1;
    }
    for (int i = 5; i < n; i++)
    {
        for (int j = i - 3; j >= max(2, i - 6); j--)
        {
            if (dp[j] + arr[ids[i]] - arr[ids[j + 1]] < dp[i])
            {
                dp[i] = dp[j] + arr[ids[i]] - arr[ids[j + 1]];
                dir[i] = j;
            }
        }
    }
    vector<int> seq;
    int v = 1, cur = n - 1;
    while (cur != -1)
    {
        int nxt = dir[cur];
        for (int i = cur; i > nxt; i--)
            team[ids[i]] = v;
        cur = nxt;
        v++;
    }
    cout << dp[n - 1] << " " << v - 1 << "\n";
    for (int t : team)
        cout << t << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}