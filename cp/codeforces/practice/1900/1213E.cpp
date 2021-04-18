// https://codeforces.com/contest/1213/problem/E
// Two Small Strings

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool same(string str)
{
    return str[0] == str[1];
}

string constructAlter(string p, int n)
{
    string str = "";
    for (int i = 0; i < n; i++)
        for (char ch : p)
            str.pb(ch);
    return str;
}

string constructSame(string p, int n)
{
    string str = "";
    for (char ch : p)
        for (int i = 0; i < n; i++)
            str.pb(ch);
    return str;
}

void solve()
{
    int n;
    string p1, p2, p = "abc";
    cin >> n >> p1 >> p2;
    bool s = same(p1) || same(p2);
    do
    {
        string cur = p;
        bool invalid = false;
        if (s && n > 1)
            cur.pb(cur[0]);
        for (int i = 1; i < cur.size(); i++)
            invalid |= (cur.substr(i - 1, 2) == p1 || cur.substr(i - 1, 2) == p2);
        if (!invalid)
        {
            cout << "YES\n";
            s ? cout << constructAlter(p, n) : cout << constructSame(p, n);
            cout << "\n";
            return;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}