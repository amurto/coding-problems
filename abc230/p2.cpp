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

bool solve()
{
    string s;
    cin >> s;
    if ((int)s.length() == 1)
        return true;
    if (s[0] == 'x')
    {
        if (s[1] == 'o')
            s = "ox" + s;
        else
            s = "o" + s;
    }
    if (s.back() == 'o')
        s = s + "xx";
    else
    {
        if (s[s.length() - 2] == 'o')
            s = s + "x";
    }
    int sz = (int)s.length();
    if (sz % 3 != 0)
        return false;
    for (int i = 0; i < sz; i += 3)
        if (s.substr(i, 3) != "oxx")
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}