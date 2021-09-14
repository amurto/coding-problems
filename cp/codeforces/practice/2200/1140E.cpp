// https://codeforces.com/contest/1140/problem/E
// Palindrome-less Arrays

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

const int MOD = 998244353;

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

int calc(vector<int> &arr, int k)
{
    int last = arr[0];
    array<int, 2> dp{0, 0};
    if (last == -1)
        dp[0] = dp[1] = 1;
    else
        dp[0] = 1;
    for (int i = 1; i < (int)arr.size(); i++)
    {
        if (arr[i - 1] != -1 && arr[i - 1] == arr[i])
            return 0;
        array<int, 2> tdp{0, 0};
        if (arr[i] == -1)
        {
            tdp[0] = mul(dp[1], k - 1);
            tdp[1] = add(dp[0], mul(dp[1], k - 2));
        }
        else
        {
            if (last == arr[i])
                tdp[0] = mul(dp[1], k - 1);
            else
                tdp[0] = add(dp[0], mul(dp[1], k - 2));
            last = arr[i];
        }
        swap(dp, tdp);
    }
    return arr.back() == -1 ? add(dp[0], mul(dp[1], k - 1)) : dp[0];
}

int solve()
{
    int n, k, v;
    cin >> n >> k;
    vector<vector<int>> arr(2);
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        arr[i & 1].pb(v);
    }
    return mul(calc(arr[0], k), calc(arr[1], k));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}