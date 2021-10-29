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

bool cnt(string &str, int n)
{
    int ab = 0, ba = 0;
    for (int i = 1; i < n; i++)
    {
        if (str[i - 1] == 'a' && str[i] == 'b')
            ab++;
        if (str[i - 1] == 'b' && str[i] == 'a')
            ba++;
    }
    return ab == ba;
}
string solve()
{
    string str;
    cin >> str;
    int n = str.length();
    if (cnt(str, n))
        return str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'a')
        {
            str[i] = 'b';
            if (cnt(str, n))
                return str;
            str[i] = 'a';
        }
        else
        {
            str[i] = 'a';
            if (cnt(str, n))
                return str;
            str[i] = 'b';
        }
    }
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}