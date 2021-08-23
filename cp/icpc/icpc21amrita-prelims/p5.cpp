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
    int n = str.length();
    char last = str[0];
    for (int i = 1; i < n; i++)
    {
        if (last == 'M' && str[i] == 'U')
            return true;
        if (str[i] != '?')
            last = str[i];
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}