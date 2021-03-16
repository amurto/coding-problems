// https://codeforces.com/contest/1286/problem/A
// Garland

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 105, inf = 1e7;
int dp[N][N][N][2];
int garland(vector<int> &arr, int cur, int odd, int evn, int last)
{
    if (odd < 0 || evn < 0)
        return inf;
    if (cur == arr.size())
        return 0;
    if (dp[cur][odd][evn][last] == -1)
    {
        int res = 0;
        if (arr[cur] > 0)
            res = ((arr[cur] % 2) != last) + garland(arr, cur + 1, odd, evn, arr[cur] % 2);
        else
            res = min((last == 0) + garland(arr, cur + 1, odd - 1, evn, 1), (last == 1) + garland(arr, cur + 1, odd, evn - 1, 0));
        dp[cur][odd][evn][last] = res;
    }
    return dp[cur][odd][evn][last];
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), vis(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        vis[arr[i]]++;
    }
    int odd = 0, evn = 0;
    for (int i = 1; i <= n; i += 2)
        if (vis[i] == 0)
            odd++;
    for (int i = 2; i <= n; i += 2)
        if (vis[i] == 0)
            evn++;
    memset(dp, -1, sizeof(dp));
    if (arr[0] > 0)
        return garland(arr, 1, odd, evn, arr[0] % 2);
    return min(garland(arr, 1, odd - 1, evn, 1), garland(arr, 1, odd, evn - 1, 0));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}