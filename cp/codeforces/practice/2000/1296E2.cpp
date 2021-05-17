// https://codeforces.com/contest/1296/problem/E2
// String Coloring (hard version)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, k = 26;
    string str;
    cin >> n >> str;
    vector<int> pdp(k), dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = k - 1; j > str[i] - 'a'; j--)
            dp[i] = max(dp[i], 1 + pdp[j]);
        pdp[str[i] - 'a'] = max(pdp[str[i] - 'a'], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}