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

const int K = 26;
string solve()
{
    string str, res = "";
    cin >> str;
    int n = str.length();
    vector<vector<int>> suf(n, vector<int>(K));
    suf[n - 1][str[n - 1] - 'a']++;
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1];
        suf[i][str[i] - 'a']++;
    }
    vector<int> cnt = suf[0];
    for (int i = 0; i < n; i++)
    {
        int cur = str[i] - 'a', mx = 0;
        for (int j = 0; j < K; j++)
            if (j != cur && suf[i][j] >= mx && cnt[j] > 0)
                mx = suf[i][j];
        vector<int> pos;
        for (int j = 0; j < K; j++)
            if (j != cur && suf[i][j] == mx)
                pos.pb(j);
        sort(pos.begin(), pos.end(), [&](int &p1, int &p2)
             { return cnt[p1] > cnt[p2]; });
        if (pos.empty() || cnt[pos[0]] == 0)
            return "IMPOSSIBLE";
        res.pb(char(pos[0] + 'a'));
        cnt[pos[0]]--;
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