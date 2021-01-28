// https://codeforces.com/contest/155/problem/C
// Hometask

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    string str, tmp;
    cin >> str >> m;
    int n = str.length();
    vector<vector<int>> g(27, vector<int>(27)), dp(n + 1, vector<int>(27));
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        g[tmp[0] - 'a'][tmp[1] - 'a'] = g[tmp[1] - 'a'][tmp[0] - 'a'] = 1;
    }
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < 27; j++)
            dp[i][j] = min(1 + dp[i + 1][j], !g[j][str[i] - 'a'] ? dp[i + 1][str[i] - 'a'] : n);
    cout << dp[0][26] << "\n";
    return 0;
}