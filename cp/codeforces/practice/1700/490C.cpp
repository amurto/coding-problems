// https://codeforces.com/contest/490/problem/C
// Hacking Cypher

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    string str;
    cin >> str;
    int n = str.length(), a, b, cur = 0, ten = 1;
    cin >> a >> b;
    vector<bool> pre(n), suf(n);
    for (int i = 0; i < n; i++)
    {
        cur = cur * 10 + (str[i] - '0');
        cur %= a;
        pre[i] = (cur == 0);
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cur = (str[i] - '0') * ten + cur;
        cur %= b;
        suf[i] = (cur == 0);
        ten = (ten * 10) % b;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (pre[i] && suf[i + 1] && str[i + 1] != '0')
        {
            cout << "YES\n";
            cout << str.substr(0, i + 1) << "\n";
            cout << str.substr(i + 1, n - i - 1) << "\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}