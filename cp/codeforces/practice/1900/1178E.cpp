// https://codeforces.com/contest/1178/problem/E
// Archaeology

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    string str, p = "abc", res = "";
    cin >> str;
    int n = str.length();
    if (n <= 3)
        return str.substr(0, 1);
    for (int i = 1, j = n - 2; i < j; i += 2, j -= 2)
    {
        char cur = 'a';
        for (char ch : p)
            if ((ch == str[i - 1] || ch == str[i]) && (ch == str[j] || ch == str[j + 1]))
                cur = ch;
        res.pb(cur);
    }
    string rev = res;
    reverse(rev.begin(), rev.end());
    if (n % 4 > 0)
        res.pb(str[n / 2]);
    return res + rev;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}