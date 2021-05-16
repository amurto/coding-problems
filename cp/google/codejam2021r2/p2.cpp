#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e6 + 5;
vector<int> divs[N];
int dp[N];
void init()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i < N; i++)
        for (int j = i; j < N; j += i)
            divs[j].pb(i);
    for (int i = 2; i < N; i++)
        for (int e : divs[i])
            dp[i] = max(dp[i], 1 + dp[(i - e) / e]);
}

int solve()
{
    int n, res = 0;
    cin >> n;
    for (int e : divs[n])
        if (e > 2)
            res = max(res, 1 + dp[(n - e) / e]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}