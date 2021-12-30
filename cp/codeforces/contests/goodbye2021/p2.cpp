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

int cnt_char(string &str)
{
    int cnt = 0;
    vector<int> freq(26);
    for (char ch : str)
        freq[ch - 'a']++;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            cnt++;
    return cnt;
}
string solve()
{
    int n;
    string str, res = "";
    cin >> n >> str;
    int i = 1;
    while (i < n && str[i - 1] > str[i])
        i++;
    string tmp = str.substr(0, i);
    if (cnt_char(tmp) == 1)
    {
        res.pb(str[0]);
        res.pb(str[0]);
        return res;
    }
    while (i < n && str[i - 1] >= str[i])
        i++;
    res = str.substr(0, i);
    string rev = res;
    reverse(rev.begin(), rev.end());
    res += rev;
    return res;
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