// https://codeforces.com/contest/157/problem/C
// Message

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int m = s2.length();
    string match = "";
    for (int i = 1; i <= m; i++)
        match.pb('0');
    for (char ch : s1)
        match.pb(ch);
    for (int i = 1; i <= m; i++)
        match.pb('0');
    int n = match.length(), res = m + 100;
    for (int i = 0; i <= n - m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
            cnt += (match[i + j] != s2[j]);
        res = min(res, cnt);
    }
    cout << res << "\n";
    return 0;
}