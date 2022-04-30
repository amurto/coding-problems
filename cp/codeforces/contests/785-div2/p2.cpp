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

bool solve()
{
    string str;
    cin >> str;
    int n = (int)str.length();
    vector<int> cnt(26), last(26);
    vector<bool> vis(26);
    vector<vector<int>> pre(n, vector<int>(26));
    for (char ch : str)
        vis[ch - 'a'] = true;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            pre[i] = pre[i - 1];
        int cur = str[i] - 'a';
        pre[i][cur]++;
        cnt[cur]++;
        if (cnt[cur] == 1)
            last[cur] = i;
        else
        {
            for (int j = 0; j < 26; j++)
                if (j != cur && vis[j] && pre[i][j] - pre[last[cur]][j] == 0)
                    return false;
            last[cur] = i;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}