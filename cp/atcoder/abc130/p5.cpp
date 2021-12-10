#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;
int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

int solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> arr1(n + 1), arr2(m + 1), st(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr1[i];
    for (int i = 1; i <= m; i++)
        cin >> arr2[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = st[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int pre = st[0];
        for (int j = 1; j <= m; j++)
        {
            if (arr1[i] == arr2[j])
                dp[i][j] = pre;
            pre = add(pre, st[j]);
        }
        for (int j = 1; j <= m; j++)
            if (arr1[i] == arr2[j])
                st[j] = add(st[j], dp[i][j]);
    }
    for (int i = 0; i <= m; i++)
        res = add(res, st[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}