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
    string str;
    cin >> str;
    int r = 0, g = 0, b = 0;
    for (char ch : str)
    {
        if (ch == 'r')
            r++;
        else if (ch == 'g')
            g++;
        else if (ch == 'b')
            b++;
        else if (ch == 'R')
        {
            if (r == 0)
                return false;
        }
        else if (ch == 'G')
        {
            if (g == 0)
                return false;
        }
        else if (ch == 'B')
        {
            if (b == 0)
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}