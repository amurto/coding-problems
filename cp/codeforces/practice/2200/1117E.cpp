// https://codeforces.com/contest/1117/problem/E
// Decypher the String

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

string query(string str)
{
    cout << "? " << str << endl;
    string ans;
    cin >> ans;
    if (ans == "0")
        exit(0);
    return ans;
}

void solve()
{
    string str, a = "", b = "", c = "";
    cin >> str;
    int n = str.length(), K = 26;
    int st[K][K][K];
    string res(n, '0');
    vector<int> ids(n);
    for (int i = 0, id = 0; id < n && i < K; i++)
    {
        for (int j = 0; id < n && j < K; j++)
        {
            for (int k = 0; id < n && k < K; k++, id++)
            {
                st[i][j][k] = id;
                a.pb(char('a' + i));
                b.pb(char('a' + j));
                c.pb(char('a' + k));
            }
        }
    }
    a = query(a);
    b = query(b);
    c = query(c);
    for (int i = 0; i < n; i++)
        ids[st[a[i] - 'a'][b[i] - 'a'][c[i] - 'a']] = i;
    for (int i = 0; i < n; i++)
        res[i] = str[ids[i]];
    cout << "! " << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

