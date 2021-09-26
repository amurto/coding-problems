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

const int MOD = 998244353, K = 10;

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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), dp(K);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp[arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        vector<int> tdp(K);
        for (int j = 0; j < K; j++)
        {
            tdp[(j + arr[i]) % 10] = add(tdp[(j + arr[i]) % 10], dp[j]);
            tdp[(j * arr[i]) % 10] = add(tdp[(j * arr[i]) % 10], dp[j]);
        }
        swap(dp, tdp);
    }
    for (int i = 0; i < K; i++)
        cout << dp[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}