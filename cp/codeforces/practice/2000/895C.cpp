// https://codeforces.com/contest/895/problem/C
// Square Subsets

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MX = 1e5 + 5, N = 71, MOD = 1e9 + 7;

// O(n)
vector<int> lp(N), pr, mask(N);
int two[MX];

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

void init()
{
    for (int i = 2; i < N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    mask[1] = 0;
    for (int i = 2; i < N; i++)
    {
        int cur = i;
        while (cur > 1)
        {
            int d = lp[cur], cnt = 0;
            int id = lower_bound(pr.begin(), pr.end(), d) - pr.begin();
            while (cur % d == 0)
            {
                cur /= d;
                cnt++;
            }
            if (cnt & 1)
                mask[i] |= (1 << id);
        }
    }
    two[0] = 1;
    for (int i = 1; i < MX; i++)
        two[i] = mul(two[i - 1], 2);
}

int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), freq(N);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int m = pr.size();
    vector<vector<int>> dp(N, vector<int>(1 << m));
    // nc0 + nc2 + nc4 + nc6 + ... = 2^(n-1)
    // nc1 + nc3 + nc5 + nc7 + ... = 2^(n-1)
    dp[0][0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = 0; j < (1 << m); j++)
        {
            if (freq[i] > 0)
            {
                dp[i][j ^ mask[i]] = add(dp[i][j ^ mask[i]], mul(dp[i - 1][j], two[freq[i] - 1]));
                dp[i][j] = add(dp[i][j], mul(dp[i - 1][j], add(two[freq[i] - 1], -1)));
            }
        }
    }
    return add(dp[N - 1][0], -1);
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