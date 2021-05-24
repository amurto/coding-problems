#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353, N = 1e6 + 5;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

// O(n)
vector<int> w(N, 1), dp(N);
void init()
{
    for (int i = 2; i < N; i++)
        for (int j = i; j < N; j += i)
            w[j]++;
    int pre = 0;
    for (int i = 1; i < N; i++)
    {
        dp[i] = add(pre, w[i]);
        pre = add(pre, dp[i]);
    }
}

int solve()
{
    int n;
    cin >> n;
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve() << "\n";
    return 0;
}