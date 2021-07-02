// https://codeforces.com/contest/235/problem/B
// Let's Play Osu!

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

double solve()
{
    int n;
    cin >> n;

    vector<double> p(n), dp(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    double res = p[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = (dp[i - 1] + p[i - 1]) * p[i];
        res += 2.0 * dp[i] + p[i];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
    cout << solve() << "\n";
    return 0;
}