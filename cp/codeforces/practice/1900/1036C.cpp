// https://codeforces.com/contest/1036/problem/C
// Classy Numbers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 20;
ll dp[N][2][4];
vector<int> num(N);

ll cn(int cur, bool f, int k)
{
    if (k > 3)
        return 0;
    if (cur == N)
        return (k > 0);
    if (dp[cur][f][k] == -1)
    {
        int limit = 9;
        if (f)
            limit = num[cur];
        ll res = 0;
        for (int i = 0; i <= limit; i++)
            if (f && i == limit)
                res += cn(cur + 1, true, k + (i > 0));
            else
                res += cn(cur + 1, false, k + (i > 0));
        dp[cur][f][k] = res;
    }
    return dp[cur][f][k];
}

ll solve(ll n)
{
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++)
        num[i] = 0;
    for (int i = N - 1; i >= 0 && n > 0; i--, n /= 10)
        num[i] = n % 10;
    return cn(0, true, 0);
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
        ll l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l - 1) << "\n";
    }
    return 0;
}