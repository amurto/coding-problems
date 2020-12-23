// https://codeforces.com/contest/584/problem/C
// Marina and Vasya

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

char diff_char(char a, char b)
{
    int i = 0;
    while (i + 'a' == a || i + 'a' == b)
        i++;
    return i + 'a';
}

string solve()
{
    int n, t, cur = 0, d = 0;
    cin >> n >> t;

    string s[2];
    cin >> s[0] >> s[1];
    string res(n, '0');
    for (int i = 0; i < n; i++)
        if (s[0][i] != s[1][i])
            d++;
    if (d / 2 + n - d < n - t)
        return "-1";
    int req = 2 * (n - t);
    vector<int> same(2, n - t);
    for (int i = 0; same[0] > 0 && same[1] > 0 && i < n; i++)
    {
        if (s[0][i] == s[1][i])
        {
            res[i] = s[0][i];
            same[0]--;
            same[1]--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (res[i] != '0')
            continue;
        if (same[cur] > 0)
        {
            res[i] = s[cur][i];
            same[cur]--;
            cur ^= 1;
        }
        else
            res[i] = diff_char(s[0][i], s[1][i]);
    }
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