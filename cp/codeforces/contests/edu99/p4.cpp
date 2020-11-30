#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 501, inf = 1e4;
int dp[N][N];

int sas(vector<int> arr, int cur, int last, int x)
{
    if (cur == arr.size())
        return 0;
    if (last > max(arr[cur], x))
        return inf;
    if (dp[cur][last] >= inf)
    {
        if (arr[cur] >= last)
            dp[cur][last] = sas(arr, cur + 1, arr[cur], x);
        if (x >= last && arr[cur] > x)
            dp[cur][last] = min(dp[cur][last], 1 + sas(arr, cur + 1, x, arr[cur]));
    }
    return dp[cur][last];
}

int solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, inf, sizeof(dp));
    int res = sas(arr, 0, 0, x);
    if (res >= inf)
        return -1;
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