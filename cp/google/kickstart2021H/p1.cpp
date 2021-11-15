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

int solve()
{
    int res = 0;
    string s, f;
    vector<bool> vis(26);
    cin >> s >> f;
    for (char ch : f)
        vis[ch - 'a'] = true;
    for (char ch : s)
    {
        int cur = ch - 'a', mn = 26;
        for (int i = cur, t = 0; t < 26; i++, t++)
        {
            i += 26;
            i %= 26;
            if (vis[i])
                mn = min(mn, t);
        }
        for (int i = cur, t = 0; t < 26; i--, t++)
        {
            i += 26;
            i %= 26;
            if (vis[i])
                mn = min(mn, t);
        }
        res += mn;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}