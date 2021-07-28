// https://codeforces.com/contest/632/problem/D
// Longest Subsequence

#ifdef amurto
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m, x;
    cin >> n >> m;
    vector<int> cnt(m + 1), dp(m + 1);
    vector<vector<int>> pos(m + 1), g(m + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x <= m)
        {
            cnt[x]++;
            pos[x].pb(i);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (cnt[i] > 0)
        {
            for (int j = i; j <= m; j += i)
            {
                dp[j] += cnt[i];
                g[j].pb(i);
            }
        }
    }
    int mx = 0, l = 1;
    for (int i = 1; i <= m; i++)
    {
        if (dp[i] > mx)
        {
            mx = dp[i];
            l = i;
        }
    }
    cout << l << " " << mx << "\n";
    vector<int> seq;
    for (int e : g[l])
        for (int i = 0; i < pos[e].size(); i++)
            seq.pb(pos[e][i]);
    sort(seq.begin(), seq.end());
    for (int e : seq)
        cout << e + 1 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}