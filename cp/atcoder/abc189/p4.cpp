#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 65;
ll dp[N][2];

ll exp(vector<string> &arr, int val, int cur, int n)
{
    if (cur == n)
        return val;
    if (dp[cur][val] == -1)
    {
        ll res = 0;
        if (arr[cur] == "AND")
            res = exp(arr, val & 1, cur + 1, n) + exp(arr, val & 0, cur + 1, n);
        else
            res = exp(arr, val | 1, cur + 1, n) + exp(arr, val | 0, cur + 1, n);
        dp[cur][val] = res;
    }
    return dp[cur][val];
}
ll solve()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    return exp(arr, 0, 0, n) + exp(arr, 1, 0, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}