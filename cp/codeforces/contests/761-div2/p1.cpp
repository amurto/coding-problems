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

string solve()
{
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    if (t == "abc")
    {
        vector<int> cnt(26);
        for (char ch : s)
            cnt[ch - 'a']++;
        if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0)
            return s;
        string res = "";
        for (int j = 0; j < cnt[0]; j++)
            res.pb('a');
        for (int j = 0; j < cnt[2]; j++)
            res.pb('c');
        for (char ch : s)
            if (ch != 'a' && ch != 'c')
                res.pb(ch);
        return res;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}