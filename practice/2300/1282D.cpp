// https://codeforces.com/contest/1282/problem/D
// Enchanted Artifact

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

int query(string str)
{
    cout << str << endl;
    int ans;
    cin >> ans;
    if (ans == -1)
        exit(0);
    return ans;
}

void solve()
{
    bool ans = false;
    int q = query("a");
    if (q == 0)
        return;
    int n = q;
    string tmp(n, 'b');
    int a = query(tmp);
    if (a == 0)
        return;
    n++;
    string str(n, 'b');
    for (int i = 0; i < n - 1; i++)
    {
        str[i] = 'a';
        int q = query(str);
        if (q == 0)
            return;
        if (q != a - 1)
            str[i] = 'b';
        if (str[i] == 'a')
            a--;
    }
    if (a > 0)
        str[n - 1] = 'a';
    query(str);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}