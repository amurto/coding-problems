#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7, N = 3e5 + 1;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int solve()
{
    string str, s = "chokudai";
    cin >> str;
    vector<int> st(26);
    for (int i = 0; i < s.length(); i++)
        st[s[i] - 'a'] = i + 1;
    vector<int> dp(9);
    dp[0] = 1;
    for (char ch : str)
    {
        if (st[ch - 'a'] > 0)
        {
            int cur = st[ch - 'a'];
            dp[cur] = add(dp[cur], dp[cur - 1]);
        }
    }
    return dp[8];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}