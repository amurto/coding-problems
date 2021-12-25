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
    string str, res = "";
    cin >> str;
    vector<int> cnt;
    int pre = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        pre += (str[i] - '0');
        cnt.pb(pre);
    }
    reverse(cnt.begin(), cnt.end());
    int sz = (int)cnt.size();
    int carry = 0;
    for (int i = 0; i < sz; i++)
    {
        int cur = cnt[i];
        cur += carry;
        res.pb(char('0' + cur % 10));
        carry = cur / 10;
    }
    reverse(res.begin(), res.end());
    if (carry > 0)
        res = to_string(carry) + res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}