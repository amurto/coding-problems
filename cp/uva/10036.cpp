// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=977
// 10036 - Divisibility

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int add(int x, int y, int k)
{
    x += y;
    while (x >= k)
        x -= k;
    while (x < 0)
        x += k;
    return x;
}

int sub(int x, int y, int k)
{
    x -= y;
    while (x >= k)
        x -= k;
    while (x < 0)
        x += k;
    return x;
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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<vector<int>> dp(n + 1, vector<int>(k));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < k; j++)
                if (dp[i - 1][j])
                    dp[i][add(j, arr[i - 1], k)] = dp[i][sub(j, arr[i - 1], k)] = 1;
        dp[n][0] ? cout << "Divisible\n" : cout << "Not divisible\n";
    }
    return 0;
}