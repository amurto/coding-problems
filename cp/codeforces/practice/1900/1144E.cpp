// https://codeforces.com/contest/1144/problem/E
// Median String

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int k;
    string str1, str2, res = "";
    cin >> k >> str1 >> str2;
    vector<int> s1(k + 1), s2(k + 1), seq(k + 2);
    for (int i = 1; i <= k; i++)
    {
        s1[i] = str1[i - 1] - 'a';
        s2[i] = str2[i - 1] - 'a';
    }
    for (int i = k; i > 0; i--)
    {
        seq[i] += s1[i] + s2[i];
        if (seq[i] >= 26)
            seq[i - 1] += seq[i] / 26;
        seq[i] %= 26;
    }
    for (int i = 0; i <= k; i++)
    {
        if (seq[i] % 2 != 0)
            seq[i + 1] += 26;
        if (i > 0)
            res.pb(char('a' + seq[i] / 2));
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