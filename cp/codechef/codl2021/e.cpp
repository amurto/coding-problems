#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e5 + 5, MOD = 1e9 + 7;
int dp[N];
int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

void init()
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i < N; i++)
        dp[i] = add(dp[i - 1], dp[i - 2]);
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
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}