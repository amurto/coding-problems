#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool dp[101][10001];

int exps(vector<int> &arr, int cur, int target)
{
    if (target == 0)
        return 1;
    if (target < 0 || cur == arr.size())
        return 0;
    if (dp[cur][target] == -1)
        dp[cur][target] = max(exps(arr, cur + 1, target), exps(arr, cur + 1, target - arr[cur]));
    return dp[cur][target];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, sum = 0;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        vector<int> arr(n), res(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            int req = arr[i] * arr[i];
            while (req <= sum)
            {
                if (exps(arr, 0, req))
                {
                    res[i] = 1;
                    break;
                }
                req *= arr[i];
            }
        }
        for (int v : res)
            cout << v << " ";
        cout << "\n";
    }
    return 0;
}